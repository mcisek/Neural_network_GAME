#ifndef GAME
#define GAME

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "map.h"
#include "player.h"

#define HEIGHT 15
#define WIDTH 20

/*TO DO:
-remove obstacles table (create additional class);

  */

class Game : public QGraphicsView//public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    QGraphicsScene *scene;
    Map *level_map; //to hold data about obstacles on whole level
    Object *obstacles[WIDTH][HEIGHT]; //to hold data about visible obstacles
    Player *player;

    Game();
    void keyPressEvent(QKeyEvent * event);

    void move_obstacles_left(int how_many_px);
    void print_obstacles_table();
};

#endif // GAME

