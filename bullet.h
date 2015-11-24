#ifndef BULLET
#define BULLET

#include <QGraphicsRectItem>
#include <QObject>
#include <QList>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();
    Bullet(int x, int y);
public slots:
    void move();
};

#endif // BULLET
