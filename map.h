#ifndef MAP
#define MAP
#include <QGraphicsItem>

#include "object.h"

#define LEVEL_WIDTH 100
#define LEVEL_HEIGHT 15

class Map : public QGraphicsRectItem
{
    int map_table[LEVEL_WIDTH][LEVEL_HEIGHT];
    int steps;
public:
    Map();
    int get_type(int x, int y);
};


#endif // MAP

