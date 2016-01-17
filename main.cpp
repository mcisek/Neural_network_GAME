#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <time.h>
#include "population.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));

    Game * game;
    game = new Game();

//    NeuralNetwork * nn = new NeuralNetwork(game);
//    game->show();

//    new NeuralNetwork();
    new Population(game);
//    Individual * in = new Individual();
//    in->start_game();


    return a.exec();
}
