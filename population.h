#ifndef POPULATION
#define POPULATION

//#include "neural_network.h"
#include "main.h"
#include "individual.h"

class Population
{
    Individual population_table[POPULATION_SIZE];
public:
    Population();
    void add_individual();
};

#endif // POPULATION

