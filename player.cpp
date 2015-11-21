#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player()
{
    setRect(0,0,40,40);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Player::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        if(x()>0)
        {
            setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if(x() < scene()->width() - rect().width())
        {
            setPos(x()+10,y());
        }
    }
}

void Player::fall()
{

}
