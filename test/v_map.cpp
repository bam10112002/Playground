#include "v_map.h"

V_Map::V_Map(QGraphicsItemGroup* group, const std::string & map_file_name,const  std::string & collection_file_name)
{
    std::ifstream collF(collection_file_name);
//    std::vector<nlohmann::json> cellsVec;
    nlohmann::json JSON{};
    collF >> JSON;
    auto cellsVec = JSON["cells"].get<std::vector<nlohmann::json>>();

    for (auto cellJson : cellsVec )
    {
        V_Cell cell(cellJson);
        collection.emplace(cell.getName(), cell);
    }


    JSON = nlohmann::json{};
    std::ifstream mapTable(map_file_name);
    mapTable >> JSON;
    std::vector<std::vector<std::string>> vector_matrix = JSON["matrix"].get<std::vector<std::vector<std::string>>>();
    int height = vector_matrix.size();
    int width = vector_matrix[0].size();

    int x, y = 0;


    for (int i = 0; i < height; i++)
        {
            x = 0;
            for (int j = 0; j < width; j++)
            {
                QGraphicsPixmapItem *item = new QGraphicsPixmapItem();
                item->setPixmap(collection[vector_matrix[i][j]].getPicture());
                item->setPos(x,y);
                group->addToGroup(item);

                x += 120;
            }
            y += 120;
        }

}

V_Cell::V_Cell(const nlohmann::json & j)
{
    name = j["name"].get<std::string>();
    cost = j["cost"].get<int>();
    picture = QPixmap(j["imgPath"].get<std::string>().c_str());
}

int V_Cell::getCost()
{
    return cost;
}

std::string V_Cell::getName()
{
    return name;
}

QPixmap V_Cell::getPicture()
{
    return picture;
}
