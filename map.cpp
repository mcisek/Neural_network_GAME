#include "map.h"

Map::Map()
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(map_table[j][i] == 1)
            {
                setRect(j*40,i*40,40,40);
            }
        }
    }
}
