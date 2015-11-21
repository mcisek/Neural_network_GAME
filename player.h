#ifndef PLAYER
#define PLAYER
#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void fall();
};
#endif // PLAYER

