#include "individual.h"
#include "math.h"
#include <cstdlib>

Individual::Individual()
{
    generate_random_chromosome();
    evaluation = 0;
}

void Individual::generate_random_chromosome()
{
    for(int i=0; i<CHROMOSOME_LENGTH; i++)
    {
        this->chromosome[i] = rand()%2;
    }
}

void Individual::mutation()
{
    if(rand()%100 <= MUTATION_CHANCE)
    {
        int mut = rand() % CHROMOSOME_LENGTH;
        this->chromosome[mut] = ~this->chromosome[mut];
    }
}

Individual Individual::hybridization(Individual in)
{
    int hyb = rand() % CHROMOSOME_LENGTH;
    for(int i=hyb; i<CHROMOSOME_LENGTH; i++)
    {
        int tmp = this->chromosome[i];
        this->chromosome[i]= in.chromosome[i];
        in.set_gen(i,tmp);
    }
    return in;
}

Individual Individual::selection(Individual in, int chance_better_lose)
{
    return in;
}

void Individual::set_gen(int gen, int value)
{
    if(gen < CHROMOSOME_LENGTH)
        if(value == 1 || value == 0)
            chromosome[gen] = value;
}
