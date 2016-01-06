#include "individual.h"
#include "math.h"
#include <cstdlib>

Individual::Individual()
{
    NeuralNetwork * nn = new NeuralNetwork;
    this->neural_net = nn;
    generate_random_chromosome();
    evaluation = 0;
}

void Individual::generate_random_chromosome()
{
    this->neural_net->generate_random_chromosome();
}

void Individual::mutation()
{
    if(rand()%100 <= MUTATION_CHANCE)
    {
        int mut = rand() % CHROMOSOME_LENGTH;
        if(this->neural_net->get_chromosome_gene(mut) == 0)
            this->neural_net->set_chromosome_gene(mut,1);
        else
            this->neural_net->set_chromosome_gene(mut,0);
    }
}

//Individual Individual::hybridization(Individual in)
//{
//    int hyb = rand() % CHROMOSOME_LENGTH;
//    for(int i=hyb; i<CHROMOSOME_LENGTH; i++)
//    {
////        int tmp = this->chromosome[i];
////        this->chromosome[i]= in.chromosome[i];
////        int tmp = this,
//    }
//    return in;
//}

//Individual Individual::selection(Individual in, int chance_better_lose)
//{
//    return in;
//}

