#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <time.h>
#include "neural_network.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));

    Game * game;
    game = new Game();

    NeuralNetwork * nn = new NeuralNetwork(game);
    game->show();

    return a.exec();
}
