#ifndef PLAYER
#define PLAYER
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    bool is_in_the_air;
    Player();
    Player(int x, int y);
    bool is_colliding_left();
    bool is_colliding_right();
    bool is_colliding_up();
    void allow_jump();
public slots:
    void fall_down();
    void jump();
};
#endif // PLAYER

