#ifndef INDIVIDUAL
#define INDIVIDUAL

//#include "neural_network.h"
#include "main.h"
#include "math.h"

#define MUTATION_CHANCE 10

class Individual
{
    int chromosome[CHROMOSOME_LENGTH];
    int evaluation;
public:
    Individual();
    void generate_random_chromosome();
    void mutation();
    Individual hybridization(Individual in);
    Individual selection(Individual in, int chance_better_lose);
    void set_gen(int gen, int value);
};

#endif // INDIVIDUAL

