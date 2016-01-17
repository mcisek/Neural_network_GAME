#include "individual.h"
#include "math.h"
#include <QTimer>
#include <cstdlib>

//Individual::Individual()
//{
//    NeuralNetwork * nn = new NeuralNetwork;
//    this->neural_net = nn;
//    generate_random_chromosome();
//    evaluation = 0;
//}


void Individual::individual_game()
{
    game_time++;
    if(game_time > MAX_GAME_TIME)
    {
        this->evaluation = this->neural_net->get_game_points();
        this->neural_net->close_game();
        this->game_state = 2;
        this->timer->stop();
    }
}


Individual::Individual()
{
    game_state = 0;
    evaluation = 0;
    game_time = 0;

    NeuralNetwork * nn = new NeuralNetwork();
    this->neural_net = nn;
    this->neural_net->generate_random_chromosome();
}

Individual::Individual(Game *game)
{
    game_state = 0;
    evaluation = 0;
    game_time = 0;

    NeuralNetwork * nn = new NeuralNetwork(game);
    this->neural_net = nn;
    this->neural_net->generate_random_chromosome();
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

void Individual::set_chromosome_gene(int num, int value)
{
    this->neural_net->set_chromosome_gene(num,value);
}

int Individual::get_chromosome_gene(int num)
{
    int tmp = this->neural_net->get_chromosome_gene(num);
    return tmp;
}

int Individual::get_evaluation()
{
    return this->evaluation;
}

void Individual::start_game()
{
    game_state = 1;
    this->neural_net->start_game();

    this->timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()),this,SLOT(individual_game()));
    this->timer->start(100);
}

int Individual::get_game_state()
{
    int x = this->game_state;
    return x;
}


