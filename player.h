#ifndef PLAYER
#define PLAYER
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player();
    Player(int x, int y);
public slots:
    void fall_down();
};
#endif // PLAYER

