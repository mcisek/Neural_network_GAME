#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include "game.h"
#include <QObject>
#include <QGraphicsView>

#define NUMBER_OF_INPUTS 10
#define NUMBER_OF_OUTPUTS 4
#define NUMBER_OF_NODES 10

class NeuralNetwork: public QObject
{
    Q_OBJECT
    Game * game;
    int input_table[NUMBER_OF_INPUTS];
    int output_table[NUMBER_OF_OUTPUTS];
    float input_table_of_importance[NUMBER_OF_INPUTS][NUMBER_OF_NODES];
    float output_table_of_importance[NUMBER_OF_OUTPUTS][NUMBER_OF_OUTPUTS];
    float nodes_values[NUMBER_OF_NODES];
public:
    NeuralNetwork(Game *game);
    void get_input_table();
    void get_nodes_values();
    void generate_output();
public slots:
    void action();
};

#endif // NEURAL_NETWORK

