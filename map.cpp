#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>

#include "map.h"

QString fileName = "C:/map_file"; //path to file with game map

Map::Map()
{
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "couldnt open map_file to read";
        return;
    }

    for(int i = 0; i<LEVEL_HEIGHT; i++)
    {
        for(int j=0; j<LEVEL_WIDTH; j++)
        {
            char a;
            file.getChar(&a);
            a == ' ';
            if(a == ' ' || a == '\n')
                file.getChar(&a);

            int b = (int) a - 48;
            map_table[j][i] = b;
        }
    }

    file.close();
}

int Map::get_type(int x, int y)
{
    return map_table[x][y];
}


