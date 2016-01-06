#ifndef INDIVIDUAL
#define INDIVIDUAL

#include "neural_network.h"
#include <QObject>

#define MUTATION_CHANCE 10

class Individual: public QObject
{
    Q_OBJECT
    NeuralNetwork * neural_net;
    int evaluation;
public:
    Individual();
    void generate_random_chromosome();
    void mutation();
    //Individual hybridization(Individual in);
    //Individual selection(Individual in, int chance_better_lose);
};

#endif // INDIVIDUAL

