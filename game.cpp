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

    level_map = new Map();

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if((i+j)%4 == 1)
            {
                obstacles[i][j] = new Object(1,40*i,40*j);
                scene->addItem(obstacles[i][j]);
            }
            else
            {
                obstacles[i][j] = new Object(0,40*i,40*j);
            }
        }
    }

    print_obstacles_table();

    player = new Player(200, 200);
    scene->addItem(player);
}

void Game::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        qDebug()<<"left";
        player->setPos(player->x()-5, player->y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        qDebug()<<"right";
        //player->setPos(player->x()+5, player->y());
        move_obstacles_left(5);
    }
    else if (event->key() == Qt::Key_Up)
    {
        qDebug()<<"up";
        player->setPos(player->x(), player->y()-5);
    }
    else if (event->key() == Qt::Key_Down)
    {
        qDebug()<<"down";
        player->setPos(player->x(), player->y()+5);
    }
}

void Game::move_obstacles_left(int how_many_px)
{
    qDebug() << "move_obstacles_left";
    for(int i=0; i<WIDTH; i++)
    {
        for(int j=0; j<HEIGHT; j++)
        {
            qDebug() << "checking if 1 == " << obstacles[i][j]->type();
            if(obstacles[i][j]->getType() == 1)
            {
                qDebug() << "move obstacle: " << i << ", " << j;
                obstacles[i][j]->setPos((obstacles[i][j]->x())-how_many_px, obstacles[i][j]->y());
            }
        }
    }
}

void Game::print_obstacles_table()
{
    qDebug() << "OBSTACLES TABLE: ";
    for(int i=0; i<WIDTH; i++)
    {
        for(int j=0; j<HEIGHT; j++)
        {
            qDebug() << i << ", " << j << ", type:" << obstacles[i][j]->getType();
        }
    }
}
