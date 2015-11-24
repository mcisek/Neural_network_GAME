#include "map.h"

Map::Map()
{
    for(int j=0; j<LEVEL_HEIGHT; j++)
    {
        for(int i=0; i<LEVEL_WIDTH; i++)
        {
            if(j==14)
                map_table[i][j] = 1;
            else
                map_table[i][j] = 0;
        }
    }

    //TO DO:
    //reading map table from file
}

int Map::get_type(int x, int y)
{
    return map_table[x][y];
}


