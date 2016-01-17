#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include "game.h"
#include <QObject>
#include <QTimer>
#include <QGraphicsView>

#define NUMBER_OF_INPUTS 8
#define NUMBER_OF_OUTPUTS 3 //left, right, up
#define NUMBER_OF_NODES 3
#define CHROMOSOME_LENGTH NUMBER_OF_NODES*(NUMBER_OF_INPUTS+NUMBER_OF_OUTPUTS)

class NeuralNetwork: public QObject
{
    Q_OBJECT
    Game * game;
    QTimer * nn_timer;
    int game_time;
    int input_table[NUMBER_OF_INPUTS];
    int output_table[NUMBER_OF_OUTPUTS];
    int input_table_of_connections[NUMBER_OF_INPUTS][NUMBER_OF_NODES];
    int nodes_table_of_connections[NUMBER_OF_NODES][NUMBER_OF_OUTPUTS];
    int nodes_values[NUMBER_OF_NODES];
    int chromosome[CHROMOSOME_LENGTH];
public:
    NeuralNetwork();
    NeuralNetwork(Game *game);
    NeuralNetwork(int chr[CHROMOSOME_LENGTH]);
    void create_chromosome();
    void generate_random_chromosome();
    void read_chromosome();
    void print_chromosome();
    void get_input_table();
    void get_nodes_values();
    void generate_output();
    void set_chromosome_gene(int num, int value);
    int get_chromosome_gene(int num);
    void start_game();
    void close_game();
    int get_game_points();
public slots:
    void action();
};

#endif // NEURAL_NETWORK

