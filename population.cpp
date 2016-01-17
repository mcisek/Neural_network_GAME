#include "population.h"
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>

QString fileName2 = "C:/population_file";

Population::Population()
{
    int i;
    for(i=0; i<POPULATION_SIZE; i++)
    {
//        this->population_table[i] = NULL;
    }
}

void Population::save_to_file()
{
    QFile file(fileName2);

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
        if(a == EOF)
            x = 0;
    }

    int i;
    for(i=0;i<10;i++)
    {
        char b = (char) i;
        file.putChar(b);
    }

    file.close();
}

void Population::load_from_file()
{
    QFile file(fileName2);

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
            int tmp = this->population_table[a].get_chromosome_gene(x);
            int val = this->population_table[b].get_chromosome_gene(x);
            this->population_table[a].set_chromosome_gene(x,val);
            this->population_table[b].set_chromosome_gene(x,tmp);
        }
    }
}
