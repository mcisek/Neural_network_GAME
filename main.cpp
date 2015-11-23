#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QGraphicsScene * scene = new QGraphicsScene();

    Game * game = new Game();

//    game->setFlag(QGraphicsItem::ItemIsFocusable);
//    game->setFocus();

    game->show();
//    scene->addItem(game);

//    QGraphicsView * view = new QGraphicsView(scene);
//    view->setFixedSize(800,600);

//    view->show();

    return a.exec();
}
