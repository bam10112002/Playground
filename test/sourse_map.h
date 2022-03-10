#ifndef SOURSE_MAP_H
#define SOURSE_MAP_H

class Coord
{
public:
    int x, y;
    Coord() {}
    Coord(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    bool operator != (const Coord& r)const
    {
        if (x == r.x && y == r.y) { return false; }
        return true;
    }
    friend bool operator < (const Coord& l ,const Coord& r)
    {
        if (l.x < r.x)
        {
            return true;
        }
        else if (l.x > r.x)
        {
            return false;
        }
        else
        {
            if (l.y < r.y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

#endif // SOURSE_MAP_H
