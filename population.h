#ifndef POPULATION
#define POPULATION

#include "neural_network.h"
#include "individual.h"

#define POPULATION_SIZE 10

class Population
{
    Individual population_table[POPULATION_SIZE];
public:
    Population();
    void add_individual();
};

#endif // POPULATION

