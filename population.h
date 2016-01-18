#ifndef POPULATION
#define POPULATION

#include "individual.h"
#include <QObject>

#define POPULATION_SIZE 3

class Population: public QObject
{
    Q_OBJECT
    int iterator;
    Individual * population_table[POPULATION_SIZE];
public:
    Population();
    Population(Game *game);
    void generate_random_population();
    void generate_random_population(Game *game);
    void save_to_file();
    void load_from_file();
    void hybridization(int a, int b);
public slots:
    void loop();
};

#endif // POPULATION

