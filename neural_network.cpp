#include "neural_network.h"
#include "math.h"
#include <cstdlib>
#include <QTimer>
#include <QDebug>


void NeuralNetwork::action()
{

    get_input_table();
    read_chromosome();
    get_nodes_values();
    generate_output();

//    print_chromosome();
//    print_input_table();
//    print_nodes_table();
//    print_output_table();

    if(output_table[0]==1)
        game->player_right();
    if(output_table[1]==1)
        game->player_up();
    if(output_table[2]==1)
        game->player_left();
    if(game->get_r_flag() == 1)
    {
        game->set_r_flag(0);
//        generate_random_chromosome();
    }

    //    game->player_right();
    //    get_input_table();
}

NeuralNetwork::NeuralNetwork()
{
    game_time = 0;

    Game * g = new Game();
    this->game = g;
    //    game->show();
}

NeuralNetwork::NeuralNetwork(Game *game)
{
    game_time = 0;
    this->game = game;

    generate_one_gene_chromosome(0);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(action()));
    timer->start(50);
}

//NeuralNetwork::NeuralNetwork(Game *game)
//{
//    this->game = game;

//    QTimer * timer = new QTimer();
//    connect(timer, SIGNAL(timeout()),this,SLOT(action()));
//    timer->start(50);

//    generate_random_chromosome();
//    print_chromosome();
//}


NeuralNetwork::NeuralNetwork(int chr[CHROMOSOME_LENGTH])
{
    for(int i=0; i<CHROMOSOME_LENGTH; i++)
        chromosome[i]=chr[i];

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

void NeuralNetwork::generate_one_gene_chromosome(int j)
{
    if(j == 1 || j == 0)
    {
        for(int i=0; i<CHROMOSOME_LENGTH; i++)
            chromosome[i]=j;
    }
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

//INPUT MODEL:
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

    int table_obstacles[INPUT_SIZE][INPUT_SIZE];

    for(int ii=0; ii<INPUT_SIZE; ii++)
    {
        for(int jj=0; jj<INPUT_SIZE; jj++)
        {
            table_obstacles[ii][jj]=0;
            this->input_table[ii*INPUT_SIZE+jj] = 0;
        }
    }

    int zero = (INPUT_SIZE-1)/2*40;

    for(int ii=0; ii<INPUT_SIZE; ii++)
    {
        for(int jj=0; jj<INPUT_SIZE; jj++)
        {
            for(int i=0; i<game_obstacles_table_width; i++)
            {
                for(int j=0; j<game_obstacles_table_height; j++)
                {
                    if(player_x >= (game->obstacles[i][j]->pos().x() - 20 - zero +(40*ii))
                            && player_x <= (game->obstacles[i][j]->pos().x() + 20 - zero + (40*ii)))
                    {
                        if(player_y >= (game->obstacles[i][j]->pos().y()-20 - zero+(40*jj))
                                && player_y <= (game->obstacles[i][j]->pos().y()+20-zero+(40*jj)))
                        {
                            table_obstacles[ii][jj]=1;
                            this->input_table[ii*INPUT_SIZE+jj] = 1;
                        }
                    }
                    //                    if((player_x - (INPUT_SIZE-1)/2*40 + 40*ii))
                    //                    if(((player_x - zero + 40*ii -20) >= game->obstacles[i][j]->pos().x())
                    //                            && ((player_x - zero + 40*ii + 20) <= game->obstacles[i][j]->pos().x()))
                    //                    {
                    //                        if(((player_y - zero + 40*jj -20) >= game->obstacles[i][j]->pos().y())
                    //                                && ((player_y - zero + 40*jj +20) <= game->obstacles[i][j]->pos().y()))
                    //                            this->input_table[ii*INPUT_SIZE+jj] = 1;
                    //                    }
                }
            }
        }
    }
}

void NeuralNetwork::get_nodes_values()
{
    for(int j=0; j<NUMBER_OF_NODES; j++)
    {
        nodes_values[j] = 0;
    }

    for(int i=0; i<NUMBER_OF_INPUTS; i++)
    {
        for(int j=0; j<NUMBER_OF_NODES; j++)
        {
            if (input_table_of_connections[i][j] == 1 && input_table[i] == 1)
                nodes_values[j] = 1;
        }
    }
}

void NeuralNetwork::generate_output()
{
    for(int j=0; j<NUMBER_OF_OUTPUTS; j++)
    {
        output_table[j] = 0;
    }

    for(int i=0; i<NUMBER_OF_NODES; i++)
    {
        for(int j=0; j<NUMBER_OF_OUTPUTS; j++)
        {
            if(nodes_table_of_connections[i][j] == 1 && nodes_values[i] == 1)
                output_table[j] = 1;
        }
    }
}

void NeuralNetwork::print_input_table()
{
    qDebug() << "INPUT TABLE: ";
    for(int i=0; i<NUMBER_OF_INPUTS; i++)
        qDebug() << i << ". - " << input_table[i];
}

void NeuralNetwork::print_output_table()
{
    qDebug() << "OUTPUT TABLE: ";
    for(int i=0; i<NUMBER_OF_OUTPUTS; i++)
        qDebug() << i << ". - " << output_table[i];
}

void NeuralNetwork::print_nodes_table()
{
    qDebug() << "NODES TABLE: ";
    for(int i=0; i<NUMBER_OF_NODES; i++)
        qDebug() << i << ". - " << nodes_values[i];
}

void NeuralNetwork::print_chromosome()
{
    qDebug() << "CHROMOSOME: ";
    for(int i=0; i<CHROMOSOME_LENGTH; i++)
        qDebug() << i << ". - " << chromosome[i];
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

void NeuralNetwork::start_game()
{
    //    Game * g = new Game();
    //    this->game = g;
    //    this->game = new Game();
    this->game->back_to_begin();
    this->game->show();

    this->nn_timer = new QTimer();
    connect(nn_timer, SIGNAL(timeout()),this,SLOT(action()));
    nn_timer->start(50);
}

void NeuralNetwork::close_game()
{
    //this->game->close();
    //    this->game->repaint();
    this->game->back_to_begin();
    nn_timer->stop();
}

int NeuralNetwork::get_game_points()
{
    int x = this->game->get_points();
    return x;
}
