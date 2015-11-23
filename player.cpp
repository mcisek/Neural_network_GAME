#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player()
{
    setRect(0,0,40,40);
}

Player::Player(int x, int y)
{
    setRect(0,0,40,40);
    setPos(x,y);
}

void Player::moveleft()
{
    setPos(x()-10, y());
}

void Player::moveright()
{
    setPos(x()+10, y());
}

