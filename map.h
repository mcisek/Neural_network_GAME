#ifndef MAP
#define MAP
#include <QGraphicsItem>

#include "object.h"

#define LEVEL_WIDTH 4
#define LEVEL_HEIGHT 4

class Map : public QGraphicsRectItem
{
    //int object_types_table[WIDTH][HEIGHT];
    int map_table[LEVEL_WIDTH][LEVEL_HEIGHT];
public:
    Map();
};


#endif // MAP

