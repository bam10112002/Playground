#include "a_map.h"

std::map<std::string, Cell::Cell_Type> Cell::convert =
{
    std::pair<std::string, Cell_Type>(std::string("EMPTY") , Cell_Type::EMPTY),
    std::pair<std::string, Cell_Type>(std::string("WALL")  , Cell_Type::WALL),
    std::pair<std::string, Cell_Type>(std::string("FOREST"), Cell_Type::FOREST)
};

bool Matrix_map::is_valid(const Coord &coord, const std::vector<std::vector<std::string> > &vec)
{
    // 0 - валидна
    // 1 - невалидна
    if (coord.x >= 0 && coord.y >= 0 && coord.x < width && coord.y < height && int(Cell::convert[vec[coord.y][coord.x]]) > 0)
    {
        return 1;
    }
    return 0;
}


A_Map::A_Map(const std::string & mapFileName)
{
    std::ifstream jf(mapFileName);
    nlohmann::json jMap{};
    jf >> jMap;

    std::vector<std::vector<std::string>> string_matrix = jMap["matrix"].get<std::vector<std::vector<std::string>>>();
    matrix = Matrix_map(string_matrix);

}

Matrix_map::Matrix_map(const std::vector<std::vector<std::string> > &vec)
{
    height = vec.size();
    width  = vec[0].size();

    matrix = new std::vector<Coord> * [height];



    for (size_t i = 0; i < height; i++)
    {
        matrix[i] = new std::vector<Coord>[width];
        for (size_t j = 0; j < width; j++)
        {
            // задаем ребра графа для каждой клетки
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (is_valid(Coord(x+j,y+i),vec) && !(x == 0 && y == 0))
                    {
                        matrix[i][j].push_back(Coord(x+j,y+i));
                    }
                }
            }
            // конец задания ребер для вершины
            qDebug() << "<< "<< j << " "<< i << ">>";
            for (auto obj :  matrix[i][j])
            {
                qDebug() << "( "<<obj.x << " "<<obj.y << ")  ";
            }
            qDebug() << "";
        }
    }
}
