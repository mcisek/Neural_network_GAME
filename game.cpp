#include <QGraphicsView>
#include <QDebug>
#include <QBrush>

#include "game.h"
#include "player.h"
#include "object.h"
#include "bullet.h"

int number_of_columns = 0;
int number_of_steps = 0;

QBrush * object_brush = new QBrush(Qt::green);

Game::Game()
{
    points = 0;
    restart_flag = 0;

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
            obstacles[i][j]->setBrush(* object_brush);
            scene->addItem(obstacles[i][j]);
        }
    }

    //print_obstacles_table();

    player = new Player(60, 60);
    scene->addItem(player);
}

void Game::player_right()
{
    if(!player->is_colliding_right())
    {
        if (player->pos().x() < 200)
        {
            player->setPos(player->x()+GAME_SPEED*5, player->y());
        }
        else
        {
            if(number_of_steps == 8)
            {
                get_new_column_from_map();
                number_of_steps = 0;
            }
            move_obstacles_left(GAME_SPEED*5);
            number_of_steps++;
            points ++;
        }
//        qDebug() << "POINTS: " << points;
    }
}

void Game::player_left()
{
    if(player->pos().x() > 0 && !player->is_colliding_left())
    {
        player->setPos(player->x()-GAME_SPEED*5, player->y());
    }
}

void Game::player_up()
{
    if(!player->is_colliding_up() && player->is_colliding_down())
        player->allow_jump();
}

void Game::player_shoot()
{
    Bullet * b = new Bullet();
    b->setPos(player->x(),player->y()+5);
    scene->addItem(b);
}

void Game::game_restart()
{
    restart_flag = 1;
}

void Game::set_r_flag(int i)
{
    restart_flag = i;
}

int Game::get_r_flag()
{
    return restart_flag;
}

int Game::get_points()
{
    int x = this->points;
    return x;
}

void Game::keyPressEvent(QKeyEvent * event)
{
    //LEFT
    if (event->key() == Qt::Key_Left)
    {
        player_left();
    }
    //RIGHT
    else if (event->key() == Qt::Key_Right)
    {
        player_right();
    }
    //UP
    else if (event->key() == Qt::Key_Up)
    {
        player_up();
    }
    //SPACE
    else if (event->key() == Qt::Key_Space)
    {
        //player_shoot();
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
        obstacles[20][i]->setBrush(* object_brush);
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

int Game::get_obstacles_table_width()
{
    int ret = WIDTH;
    return ret;
}

int Game::get_obstacles_table_height()
{
    int ret = HEIGHT;
    return ret;
}
