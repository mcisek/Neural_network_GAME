#include <QKeyEvent>

#include <object.h>

Object::Object()
{
    setRect(0,0,40,40);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

Object::Object(int type, int x, int y)
{
    object_type = type;
    setRect(0,0,40,40);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(x, y);
}

void Object::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if(object_type == 2)
        {
            setPos(x()-10,y());
        }
        if(object_type == 3)
        {
            setPos(x()-1,y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if(object_type == 2)
        {
            setPos(x()+10,y());
        }
        if(object_type == 3)
        {
            setPos(x()+1,y());
        }
    }
}
