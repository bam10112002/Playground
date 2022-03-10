#ifndef A_MAP_H
#define A_MAP_H

#include <string>
#include <fstream>
#include <map>
#include <vector>

#include <QDebug>
#include "sourse_map.h"
#include "../json/single_include/nlohmann/json.hpp"

class Cell;
class A_Map;
class Matrix_map;

class Matrix_map
{
private:
    std::vector<Coord>** matrix;
    size_t width;
    size_t height;

    bool is_valid(const Coord & coord, const std::vector<std::vector<std::string>> & vec);

public:
    Matrix_map(){}
    Matrix_map(const std::vector<std::vector<std::string>> & vec);
};

class A_Map
{
private:
   Matrix_map matrix;

public:
   A_Map(){}
   A_Map(const std::string & mapFileName);
};

class Cell
{
private:
public :
    enum class Cell_Type { NONE = 0, EMPTY = 10, WALL = -1, FOREST = 20 };
    static std::map<std::string, Cell_Type> convert;

    Coord coord;
    Cell_Type type;

    Cell(Cell_Type tp, Coord coord);
    Cell(){}
};

#endif // A_MAP_H
