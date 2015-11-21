#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "player.h"
#include "map.h"
#include "object.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    Object * ob2 = new Object(2, 40, 40);
    Object * ob3 = new Object(3, 80, 80);

    scene->addItem(ob2);
    scene->addItem(ob3);

    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(800,600);

    view->show();

    return a.exec();
}
