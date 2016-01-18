#include "population.h"
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QTimer>

QString populationFileName = "C:/population_file";

void Population::loop()
{
    if(iterator < POPULATION_SIZE)
    {
        if(this->population_table[iterator]->get_game_state() == 0)
        {
            qDebug() << "INDIVIDUAL START: " << iterator << " ";
            this->population_table[iterator]->start_game();
        }
        else if (this->population_table[iterator]->get_game_state() == 2)
        {
            qDebug() << "INDIVIDUAL END: " << iterator << " ";
            iterator++;
        }
    }
    if(iterator == POPULATION_SIZE)
    {
        this->save_to_file();
        iterator++;
    }
}

Population::Population()
{
    //load_from_file();
    iterator = 0;
    generate_random_population();

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(loop()));
    timer->start(10);
}

Population::Population(Game *game)
{
    iterator = 0;
    generate_random_population(game);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(loop()));
    timer->start(10);
}

void Population::generate_random_population()
{
    for(int i=0; i<POPULATION_SIZE; i++)
    {
        this->population_table[i] = new Individual();
        this->population_table[i]->generate_random_chromosome();
    }
}

void Population::generate_random_population(Game *game)
{
    for(int i=0; i<POPULATION_SIZE; i++)
    {
        this->population_table[i] = new Individual(game);
        this->population_table[i]->generate_random_chromosome();
    }
}

void Population::save_to_file()
{
    QFile file(populationFileName);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        //qDebug() << "couldnt open map_file to read";
        return;
    }

    for(int i=0;i<POPULATION_SIZE;i++)
    {
        for(int j=0; j<CHROMOSOME_LENGTH; j++)
        {
            char b = ((char) this->population_table[i]->get_chromosome_gene(j)) + 48;
            file.putChar(b);
        }
        file.putChar('\n');
    }

    file.close();
}

void Population::load_from_file()
{
    QFile file(populationFileName);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        //qDebug() << "couldnt open map_file to read";
        return;
    }

    int x = 1;

    while(x==1)
    {
        char a;
        file.getChar(&a);
        if(a != '!')
            x = 0;

    }

    //    for(int i = 0; i<LEVEL_HEIGHT; i++)
    //    {
    //        for(int j=0; j<LEVEL_WIDTH; j++)
    //        {
    //            char a;
    //            file.getChar(&a);
    //            if(a == ' ' || a == '\n')
    //                file.getChar(&a);

    //            int b = (int) a - 48;
    //            map_table[j][i] = b;
    //        }
    //    }

    file.close();
}

void Population::hybridization(int a, int b)
{
    if(a < POPULATION_SIZE && b < POPULATION_SIZE)
    {
        int x = rand() % CHROMOSOME_LENGTH;
        for(x; x < CHROMOSOME_LENGTH; x++)
        {
            int tmp = this->population_table[a]->get_chromosome_gene(x);
            int val = this->population_table[b]->get_chromosome_gene(x);
            this->population_table[a]->set_chromosome_gene(x,val);
            this->population_table[b]->set_chromosome_gene(x,tmp);
        }
    }
}

