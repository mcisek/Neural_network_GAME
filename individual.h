#ifndef INDIVIDUAL
#define INDIVIDUAL

#include "neural_network.h"
#include <QObject>

#define MUTATION_CHANCE 10
#define MAX_GAME_TIME 100

class Individual: public QObject
{
    Q_OBJECT
    int is_game_finished;
    int evaluation;
    int game_time;
    NeuralNetwork * neural_net;
public:
    Individual();
    void generate_random_chromosome();
    void mutation();
    void set_chromosome_gene(int num, int value);
    int get_chromosome_gene(int num);
    int get_evaluation();
    void start_game();
    int get_game_state();
public slots:
    void individual_game();
};

#endif // INDIVIDUAL

