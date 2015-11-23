#ifndef PLAYER
#define PLAYER
#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player();
    Player(int x, int y);
    void moveleft();
    void moveright();
};
#endif // PLAYER

