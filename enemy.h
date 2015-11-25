#ifndef ENEMY
#define ENEMY

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bool is_in_the_air;
    Enemy();
    Enemy(int x, int y);
    bool is_colliding_left();
    bool is_colliding_right();
    bool is_colliding_up();
    bool is_colliding_down();
public slots:
    void move();
};

#endif // ENEMY

