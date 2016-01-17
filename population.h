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
    void save_to_file();
    void load_from_file();
    void hybridization(int a, int b);
};

#endif // POPULATION

