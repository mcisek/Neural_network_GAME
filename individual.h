#ifndef INDIVIDUAL
#define INDIVIDUAL

#include "neural_network.h"
#include <QObject>
#include <QTimer>

#define MAX_GAME_TIME 10000

class Individual: public QObject
{
    Q_OBJECT
    int game_state; //0 - not started; 1 - started; 2 - finished
    int evaluation;
    int game_time;
    QTimer * timer;
    NeuralNetwork * neural_net;
public:
    Individual();
    Individual(Game * game);
    void generate_random_chromosome();
    void generate_one_gene_chromosome(int i);
    void set_chromosome_gene(int num, int value);
    int get_chromosome_gene(int num);
    int get_evaluation();
    void start_game();
    int get_game_state();
public slots:
    void individual_game();
};

#endif // INDIVIDUAL

