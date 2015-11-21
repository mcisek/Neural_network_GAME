#ifndef OBJECT
#define OBJECT

#include <QGraphicsRectItem>
#include <QObject>

class Object : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    int object_type;
public:
    Object();
    Object(int type, int x, int y);
    void keyPressEvent(QKeyEvent * event);
};

#endif // OBJECT

