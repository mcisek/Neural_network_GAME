#ifndef POPULATION
#define POPULATION

#include "individual.h"
#include <QObject>

#define POPULATION_SIZE 5

class Population: public QObject
{
    Q_OBJECT
    int iterator;
    Individual * population_table[POPULATION_SIZE];
public:
    Population();
    void generate_random_population();
    void save_to_file();
    void load_from_file();
    void hybridization(int a, int b);
public slots:
    void loop();
};

#endif // POPULATION

