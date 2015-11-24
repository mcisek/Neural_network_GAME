#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

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
//    setPos(x(), y()+5);
}

