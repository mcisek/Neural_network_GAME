#ifndef POPULATION
#define POPULATION

#include "individual.h"
#include <QObject>

#define POPULATION_SIZE 10

class Population: public QObject
{
    Q_OBJECT
    Individual population_table[POPULATION_SIZE];
public:
    Population();
    void add_individual();
    Population generate_new_population();
};

#endif // POPULATION

