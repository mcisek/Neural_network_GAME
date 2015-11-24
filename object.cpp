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
    if(type != 0)
    {
        object_type = type;
        setRect(0,0,40,40);
        setFlag(QGraphicsItem::ItemIsFocusable);
        setFocus();
        setPos(x, y);
    }
    else
        object_type = type;
}

void Object::move_left()
{
    setPos(x()-10, y());
}

void Object::move_right()
{
    setPos(x()+10, y());
}

int Object::getType()
{
    return object_type;
}
