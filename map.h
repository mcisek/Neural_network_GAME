#ifndef MAP
#define MAP
#include <QGraphicsItem>

#define HEIGHT 4
#define WIDTH 4

class Map : public QGraphicsRectItem
{
    int map_table[WIDTH][HEIGHT];
public:
    Map();
};


#endif // MAP

