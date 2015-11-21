#ifndef MAP
#define MAP
#include <QGraphicsItem>

#define HEIGHT 15
#define WIDTH 20

class Map : public QGraphicsRectItem
{
    int map_table[WIDTH][HEIGHT];
public:
    Map();
};


#endif // MAP

