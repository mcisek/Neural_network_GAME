#include <QDebug>
#include <QList>
//#include <QKeyEvent>
//#include <QGraphicsScene>

#include "player.h"
#include "object.h"

Player::Player()
{
    setRect(0,0,40,40);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(fall_down()));
    timer->start(50);
}

Player::Player(int x, int y)
{
    setRect(0,0,40,40);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(fall_down()));
    timer->start(50);

    setPos(x,y);
}

void Player::fall_down()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0; i<colliding_items.size(); i++)
    {
        if(typeid(* (colliding_items[i])) == typeid(Object))
        {
            if(colliding_items[i]->pos().y() == pos().y() + 40)
                return;
        }

    }
    setPos(x(), y()+5);
}

