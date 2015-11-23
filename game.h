#ifndef GAME
#define GAME

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "object.h"
#include "player.h"

class Game : public QGraphicsView//public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    QGraphicsScene *scene;
    Object *ob1;
    Player *player;
    Game();
    void keyPressEvent(QKeyEvent * event);
};

#endif // GAME

