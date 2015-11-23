#include <QGraphicsView>
#include <QDebug>

#include "game.h"
#include "player.h"
#include "object.h"

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    ob1 = new Object(1, 0, 0);
    scene->addItem(ob1);

    player = new Player(200, 200);
    scene->addItem(player);

    qDebug()<<"construct";
}

void Game::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        qDebug()<<"left";
        ob1->setPos(ob1->x()-10, ob1->y());
        player->setPos(player->x()+1, player->y()+5);
    }
    else if (event->key() == Qt::Key_Right)
    {
        qDebug()<<"right";
        ob1->setPos(ob1->x()+10, ob1->y());
        player->setPos(player->x()-1, player->y()-5);
    }
}
