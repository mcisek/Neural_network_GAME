#ifndef POPULATION
#define POPULATION

#include "individual.h"
#include <QObject>

#define POPULATION_SIZE 1
#define MUTATION_CHANCE 15 //<100
#define HYBRIDIZATION_CHANCE 95 //<100

class Population: public QObject
{
    Q_OBJECT
    int iterator;
    QTimer * timer;
    Individual * population_table[POPULATION_SIZE];
    Individual * child_population_table[POPULATION_SIZE];
    Game * game;
public:
    Population();
    Population(Game *game);
    void generate_random_population();
    void generate_random_population(Game *game);
    void generate_one_gene_population(Game *game, int i);
    void save_to_file();
    void save_child_population_to_file();
    void load_from_file();
    void print_population();
    void hybridization(int a, int b);
    void mutation(int a);
    void selection();
public slots:
    void loop();
};

#endif // POPULATION

