#include "neural_network.h"
#include "math.h"
#include <cstdlib>
#include <QTimer>
#include <QDebug>


void NeuralNetwork::action()
{
    //        generate_random_chromosome();

    get_input_table();
    read_chromosome();
    get_nodes_values();
    generate_output();

    if(output_table[0]==1)
        game->player_right();
    if(output_table[1]==1)
        game->player_up();
    if(output_table[2]==1)
        game->player_left();
    if(game->get_r_flag() == 1)
    {
        game->set_r_flag(0);
        generate_random_chromosome();
    }
    //    game->player_right();
    //    get_input_table();
}

NeuralNetwork::NeuralNetwork()
{
    Game * g = new Game();
    this->game = g;
    game->show();

    QTimer * timer = new QTimer();
    //connect(timer, SIGNAL(timeout()),this,SLOT(action()));
    timer->start(50);
}

NeuralNetwork::NeuralNetwork(Game *game)
{
    this->game = game;

    QTimer * timer = new QTimer();
    //connect(timer, SIGNAL(timeout()),this,SLOT(action()));
    timer->start(50);

    generate_random_chromosome();
    print_chromosome();
}

NeuralNetwork::NeuralNetwork(int chr[CHROMOSOME_LENGTH])
{
    for(int i=0; i<CHROMOSOME_LENGTH; i++)
        chromosome[i]=chr[i];

    Game * g = new Game();
    this->game = g;
    game->show();

    QTimer * timer = new QTimer();
    //connect(timer, SIGNAL(timeout()),this,SLOT(action()));
    timer->start(50);
}

void NeuralNetwork::create_chromosome()
{

}

void NeuralNetwork::generate_random_chromosome()
{
    for(int i=0; i<CHROMOSOME_LENGTH; i++)
        chromosome[i]=rand()%2; //generate 0 or 1
}

void NeuralNetwork::read_chromosome()
{
    for(int i=0; i<NUMBER_OF_INPUTS; i++)
    {
        for(int j=0; j<NUMBER_OF_NODES; j++)
        {
            int x = i*NUMBER_OF_NODES+j;
            input_table_of_connections[i][j]=chromosome[x];
        }
    }
    for(int i=0; i<NUMBER_OF_NODES; i++)
    {
        for(int j=0; j<NUMBER_OF_OUTPUTS; j++)
        {
            int x = NUMBER_OF_INPUTS*NUMBER_OF_NODES + i*NUMBER_OF_OUTPUTS + j;
            nodes_table_of_connections[i][j] = chromosome[x];
        }
    }
}

void NeuralNetwork::print_chromosome()
{
    for(int i=0; i<CHROMOSOME_LENGTH; i++)
        qDebug() << chromosome[i] << " ";
}

//INPUT MODEL::
// . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . .
// . . . . . . 1 2 3 . . . . . . .
// . . . . . . 4 X 5 . . . . . . .
// . . . . . . 6 7 8 . . . . . . .
// . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . .

void NeuralNetwork::get_input_table()
{
    int player_x = game->player->pos().x();
    int player_y = game->player->pos().y();

    int game_obstacles_table_width = game->get_obstacles_table_width();
    int game_obstacles_table_height = game->get_obstacles_table_height();

    int table_obstacles[3][3];

    for(int ii=0; ii<3; ii++)
    {
        for(int jj=0; jj<3; jj++)
        {
            table_obstacles[ii][jj]=0;
        }
    }

    for(int ii=0; ii<3; ii++)
    {
        for(int jj=0; jj<3; jj++)
        {
            for(int i=0; i<game_obstacles_table_width; i++)
            {
                for(int j=0; j<game_obstacles_table_height; j++)
                {
                    if(player_x >= (game->obstacles[i][j]->pos().x() - 60 +(40*ii))
                            && player_x <= (game->obstacles[i][j]->pos().x() - 20 + (40*ii)))
                    {
                        if(player_y >= (game->obstacles[i][j]->pos().y()-60+(40*jj))
                                && player_y <= (game->obstacles[i][j]->pos().y()-20+(40*jj)))
                        {
                            table_obstacles[ii][jj]=1;
                        }
                    }
                }
            }
        }
    }


    //    qDebug() << "INPUT:";

    //    qDebug() << table_obstacles[2][2] << " " << table_obstacles[1][2] << " " << table_obstacles[0][2];
    //    qDebug() << table_obstacles[2][1] << " " << "X" << " " << table_obstacles[0][1];
    //    qDebug() << table_obstacles[2][0] << " " << table_obstacles[1][0] << " " << table_obstacles[0][0];

    //qDebug() << "INPUT: " << input_table[0] << ", " << input_table[1] << ", " << input_table[2] << ", " << input_table[3] << ", " << input_table[4] << ", " << input_table[5] << ", " << input_table[6] << ", " << input_table[7];
}

void NeuralNetwork::get_nodes_values()
{
    for(int i=0; i<NUMBER_OF_INPUTS; i++)
    {
        for(int j=0; j<NUMBER_OF_NODES; j++)
        {
            if(i==0)
                nodes_values[j]=0; //seting initial value
            if (input_table_of_connections[i][j] == 1)
                nodes_values[j] = 1;
        }
    }
}

void NeuralNetwork::generate_output()
{
    for(int i=0; i<NUMBER_OF_NODES; i++)
    {
        for(int j=0; j<NUMBER_OF_OUTPUTS; j++)
        {
            if (i==0)
                output_table[j] = 0;
            if(nodes_table_of_connections[i][j] == 1)
                output_table[j] = 1;
        }
    }
}

int NeuralNetwork::get_chromosome_gene(int num)
{
    int tmp = -1;
    if(num < CHROMOSOME_LENGTH)
        tmp = this->chromosome[num];
    return tmp;
}

void NeuralNetwork::set_chromosome_gene(int num, int value)
{
    if(num < CHROMOSOME_LENGTH)
    {
        if(value == 1 || value == 0)
            this->chromosome[num] = value;
    }
}
