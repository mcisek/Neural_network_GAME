#include <QTimer>
#include <QGraphicsScene>

#include "bullet.h"
#include "object.h"
#include "enemy.h"

Bullet::Bullet()
{
    setRect(45,0,10,10);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

Bullet::Bullet(int x, int y)
{
    setRect(45,0,10,10);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

    setPos(x,y);
}

void Bullet::move()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0; i<colliding_items.size(); i++)
    {
//        if(typeid(* (colliding_items[i])) == typeid(Enemy))
//        {
//            scene()->removeItem(colliding_items[i]);
//            delete colliding_items[i];

//            scene()->removeItem(this);
//            delete this;
//            return;
//        }
        if(typeid(* (colliding_items[i])) == typeid(Object))
        {
            scene()->removeItem(this);
            delete this;
            return;
        }

    }

    //move
    setPos(x()+10,y());

    //destroy
    if( pos().x() > 810)
    {
        scene()->removeItem(this);
        delete this;
    }

}
