#include <QGraphicsView>
#include <QDebug>

#include "game.h"
#include "player.h"
#include "object.h"
#include "bullet.h"

int number_of_columns = 0;
int number_of_steps = 0;

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    level_map = new Map();

    for(int i=0;i<WIDTH;i++)
    {
        for(int j=0;j<HEIGHT;j++)
        {
            int type = level_map->get_type(i,j);
            obstacles[i][j] = new Object(type,40*i,40*j);
            scene->addItem(obstacles[i][j]);
        }
    }

    //print_obstacles_table();

    player = new Player(200, 200);
    scene->addItem(player);
}

void Game::keyPressEvent(QKeyEvent * event)
{
    //LEFT
    if (event->key() == Qt::Key_Left)
    {
        if(player->pos().x() > 0 && !player->is_colliding_left())
            player->setPos(player->x()-5, player->y());
    }
    //RIGHT
    else if (event->key() == Qt::Key_Right)
    {
        if(!player->is_colliding_right())
        {
            if (player->pos().x() < 200)
                player->setPos(player->x()+5, player->y());
            else
            {
                if(number_of_steps == 8)
                {
                    get_new_column_from_map();
                    number_of_steps = 0;
                }
                move_obstacles_left(5);
                number_of_steps++;
            }
        }
    }
    //UP
    else if (event->key() == Qt::Key_Up)
    {
        if(!player->is_colliding_up())
            player->allow_jump();
//            player->setPos(player->x(), player->y()-5);
    }
    //DOWN
    else if (event->key() == Qt::Key_Down)
    {
//        player->setPos(player->x(), player->y()+5);
    }
    //SPACE
    else if (event->key() == Qt::Key_Space)
    {
        Bullet * b = new Bullet();
        b->setPos(player->x(),player->y()+5);
        scene->addItem(b);
    }
}

void Game::move_obstacles_left(int how_many_px)
{
    for(int i=0; i<WIDTH; i++)
    {
        for(int j=0; j<HEIGHT; j++)
        {
            if(obstacles[i][j]->getType() == 1)
            {
                obstacles[i][j]->setPos((obstacles[i][j]->x())-how_many_px, obstacles[i][j]->y());
            }
        }
    }
}

void Game::get_new_column_from_map()
{
    for(int i=0; i<HEIGHT; i++)
    {
        scene->removeItem(obstacles[0][i]);
        delete obstacles[0][i];
    }
    for(int i=1; i<WIDTH; i++)
    {
        for(int j=0; j<HEIGHT; j++)
        {
            obstacles[i-1][j]=obstacles[i][j];
        }
    }
    for(int i=0; i<HEIGHT; i++)
    {
        obstacles[20][i] = new Object (level_map->get_type(20+number_of_columns,i), 40*20, 40*i);
        scene->addItem(obstacles[20][i]);
    }
    number_of_columns++;
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
