#include "population.h"
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QTimer>

QString populationFileName = "C:/population_file";
QString populationFileNameTest = "C:/population_file_test";

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
        //        this->load_from_file();
        //this->save_to_file();
        //        this->selection();
        //        for(int i = 1; i < POPULATION_SIZE; i++)
        //            child_population->hybridization(i-1,i);
        //        for(int i = 1; i < POPULATION_SIZE; i++)
        //            child_population->mutation(i);
        this->selection();
                this->save_child_population_to_file();
        iterator++;
    }
}

Population::Population()
{
    //load_from_file();
    iterator = 0;
    generate_random_population();
    //    this->load_from_file();

    //    Game * game = new Game();
    //    generate_one_gene_population(game, 1);

    this->timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(loop()));
    timer->start(10);
}

Population::Population(Game *game)
{
    iterator = 0;
    this->game = game;
    //    generate_random_population(this->game);
    generate_one_gene_population(game, 0);
    this->load_from_file();

//    for(int i=1; i<POPULATION_SIZE; i++)
//        this->hybridization(i-1,i);
    //    for(int i=0; i<POPULATION_SIZE; i++);
    //        this->mutation(i);

//    this->print_population();
//    this->save_to_file();

    this->timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(loop()));
    timer->start(10);
}

void Population::generate_random_population()
{
    for(int i=0; i<POPULATION_SIZE; i++)
    {
        this->population_table[i] = new Individual();
        this->child_population_table[i] = new Individual();
        this->population_table[i]->generate_random_chromosome();
    }
}

void Population::generate_random_population(Game *game)
{
    for(int i=0; i<POPULATION_SIZE; i++)
    {
        this->population_table[i] = new Individual(game);
        this->child_population_table[i] = new Individual(game);
        this->population_table[i]->generate_random_chromosome();
    }
}

void Population::generate_one_gene_population(Game *game, int j)
{
    for(int i=0; i<POPULATION_SIZE; i++)
    {
        this->population_table[i] = new Individual(game);
        this->child_population_table[i] = new Individual(game);
        this->population_table[i]->generate_one_gene_chromosome(j);
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
        //saving chromosome
        for(int j=0; j<CHROMOSOME_LENGTH; j++)
        {
            char b = ((char) this->population_table[i]->get_chromosome_gene(j)) + 48;
            file.putChar(b);
        }
        file.putChar('\n');
    }

    file.close();
}

void Population::save_child_population_to_file()
{

    QFile file(populationFileName);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        //qDebug() << "couldnt open map_file to read";
        return;
    }

    for(int i=0;i<POPULATION_SIZE;i++)
    {
        //saving chromosome
        for(int j=0; j<CHROMOSOME_LENGTH; j++)
        {
            char b = ((char) this->child_population_table[i]->get_chromosome_gene(j)) + 48;
            file.putChar(b);
        }
        file.putChar('\n');
    }

    file.close();

}

void Population::load_from_file()
{
    QFile file(populationFileNameTest);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        //qDebug() << "couldnt open map_file to read";
        return;
    }

    for(int i = 0; i<POPULATION_SIZE; i++)
    {
        for(int j=0; j<CHROMOSOME_LENGTH; j++)
        {
            char a;
            file.getChar(&a);
            if(a == '\n' || a == ' ')
                file.getChar(&a);
            if(a == '1')
                this->population_table[i]->set_chromosome_gene(j,1);
            else if(a == '0')
                this->population_table[i]->set_chromosome_gene(j,0);
        }
    }

    file.close();
}

void Population::print_population()
{
    for(int i=0; i<POPULATION_SIZE; i++)
    {
        qDebug() << "INDIVIDUAL: " << i;

        for(int j=0; j<CHROMOSOME_LENGTH; j++)
        {
            qDebug() << this->population_table[i]->get_chromosome_gene(j);
        }
    }
}

void Population::hybridization(int a, int b)
{
    if(rand()%100 <= HYBRIDIZATION_CHANCE)
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
}

void Population::mutation(int a)
{
    if(rand() % 100 <= MUTATION_CHANCE)
    {
        int x = rand() % CHROMOSOME_LENGTH;
        if(this->population_table[a]->get_chromosome_gene(x) == 1)
            this->population_table[a]->set_chromosome_gene(x,0);
        else
            this->population_table[a]->set_chromosome_gene(x,1);
    }
}

void Population::selection()
{
    int evaluation_sum = 0;
    for(int i=0; i<POPULATION_SIZE; i++)
        evaluation_sum = evaluation_sum + this->population_table[i]->get_evaluation();

    qDebug() << "Evaluation sum: " << evaluation_sum ;

    if(evaluation_sum != 0)
    {
        for(int i=0; i<POPULATION_SIZE; i++)
        {
            int next = 0;
            qDebug() << i << " of " << POPULATION_SIZE;
            int rnd = rand() % evaluation_sum;
            int part = 0;//this->population_table[j]->get_evaluation();
            for(int j=0; j<POPULATION_SIZE; j++)
            {
                part = part + this->population_table[j]->get_evaluation();
                qDebug() << "current part: " << part << "   current rnd: " << rnd;
                if(rnd <= part) //BUG!!! true in most of cases
                {
                    if(this->population_table[j]->get_evaluation() != 0 && next == 0)
                    {
                        for(int z=0; z<CHROMOSOME_LENGTH; z++)
                            this->child_population_table[i]->set_chromosome_gene(z,this->population_table[j]->get_chromosome_gene(z));
                        next = 1;
                    }
                }
            }
        }
    }
    else
    {
        for(int i=0;i<POPULATION_SIZE;i++)
        {
            for(int j=0;j<CHROMOSOME_LENGTH;j++)
                this->child_population_table[i]->set_chromosome_gene(j,this->population_table[i]->get_chromosome_gene(j));
        }
    }
}
