#include "neural_network.h"
#include "math.h"
#include <QTimer>


void NeuralNetwork::action()
{
    game->player_right();
}

NeuralNetwork::NeuralNetwork(Game *game)
{
    this->game = game;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(action()));
    timer->start(50);
}

void NeuralNetwork::get_input_table()
{

}

void NeuralNetwork::get_nodes_values()
{
    for(int i=0; i<NUMBER_OF_INPUTS; i++)
    {
        for(int j=0; j<NUMBER_OF_NODES; j++)
        {
            if(i==0)
                nodes_values[j]=0;
            nodes_values[j] += input_table[i]*input_table_of_importance[i][j];
        }
    }
}

void NeuralNetwork::generate_output()
{
    float output_sums[NUMBER_OF_OUTPUTS];
    float total_sum = 0;
    for(int i=0; i<NUMBER_OF_NODES; i++)
    {
        for(int j=0; j<NUMBER_OF_OUTPUTS; j++)
        {
            if(i==0)
                output_sums[j]=0;
            output_sums[j] += nodes_values[i]*output_table_of_importance[j][i];
        }
        total_sum += output_sums[i];
    }

    for(int i=0; i<NUMBER_OF_NODES; i++)
    {
        if(output_sums[i] > total_sum/NUMBER_OF_OUTPUTS)
            output_table[i]=1;
        else
            output_table[i]=0;
    }
}
