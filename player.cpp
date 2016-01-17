#include <QDebug>
#include <QList>
#include <QBrush>
//#include <QKeyEvent>
//#include <QGraphicsScene>

#define JUMP_ALTITUDE 30

#include "player.h"
#include "object.h"
#include "game.h"

int vertical_steps = 0;
bool jumping = false;

Player::Player()
{
    setRect(0,0,40,40);
    setBrush(* new QBrush(Qt::black));
    is_in_the_air = false;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(fall_down()));
    connect(timer, SIGNAL(timeout()),this,SLOT(jump()));
    timer->start(50);
}

Player::Player(int x, int y)
{
    setRect(0,0,40,40);
    setBrush(* new QBrush(Qt::black));
    is_in_the_air = true;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(fall_down()));
    connect(timer, SIGNAL(timeout()),this,SLOT(jump()));
    timer->start(50);

    setPos(x,y);
}

bool Player::is_colliding_left()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0; i<colliding_items.size(); i++)
    {
        if(typeid(* (colliding_items[i])) == typeid(Object))
        {
            if(colliding_items[i]->pos().x() == pos().x() - 40)
                if(colliding_items[i]->pos().y() != pos().y() + 40)
                    return true;
        }
    }
    return false;
}

bool Player::is_colliding_right()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0; i<colliding_items.size(); i++)
    {
        if(typeid(* (colliding_items[i])) == typeid(Object))
        {
            if(colliding_items[i]->pos().x() == pos().x() + 40)
                if(colliding_items[i]->pos().y() != pos().y() + 40)
                    return true;
        }
    }
    return false;
}

bool Player::is_colliding_up()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0; i<colliding_items.size(); i++)
    {
        if(typeid(* (colliding_items[i])) == typeid(Object))
        {
            if(colliding_items[i]->pos().y() == pos().y() - 40)
                if(colliding_items[i]->pos().x() > pos().x() - 40 &&
                        colliding_items[i]->pos().x() < pos().x() + 40)
                    return true;
        }
    }
    return false;
}

bool Player::is_colliding_down()
{
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0; i<colliding_items.size(); i++)
    {
        if(typeid(* (colliding_items[i])) == typeid(Object))
        {
            if(colliding_items[i]->pos().y() == pos().y() + 40)
                if(colliding_items[i]->pos().x() > pos().x() - 40 &&
                        colliding_items[i]->pos().x() < pos().x() + 40)
                    return true;
        }
    }
    return false;
}

void Player::allow_jump()
{
    if(!is_in_the_air)
    {
        vertical_steps = 0;
        jumping = true;
    }
}

void Player::fall_down()
{
    if(!jumping)
    {
        if(is_colliding_down())
        {
            is_in_the_air = false;
            vertical_steps = 0;
            return;
        }
        setPos(x(), y()+GAME_SPEED*5);
    }
}

void Player::jump()
{
    if(jumping && vertical_steps != JUMP_ALTITUDE && !is_colliding_up())
    {
        vertical_steps ++;
        setPos(x(), y()-GAME_SPEED*5);
    }
    else if (vertical_steps == JUMP_ALTITUDE || is_colliding_up())
    {
        jumping = false;
    }
}

