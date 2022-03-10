#ifndef V_MAP_H
#define V_MAP_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "../json/single_include/nlohmann/json.hpp"


class V_Cell;
class V_Map
{

private:
    std::map<std::string,V_Cell> collection;

public:
    V_Map(){};
    V_Map(QGraphicsItemGroup* group, const std::string & map_file_name,const  std::string & collection_file_name);

};



class V_Cell
{
private:
    QPixmap picture;
    int cost;
    std::string name;

public:
    V_Cell(const nlohmann::json & j);
    V_Cell(){};
    int getCost();
    std::string getName();
    QPixmap getPicture();
};

#endif // V_MAP_H
