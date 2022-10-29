//Fawaz Asif - 1001875463

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DrawTool.h"

int main(void)
{
    char DimArray[MAXMAPSIZE][MAXMAPSIZE];
    int MapSize;
    char *parse;
    char letter[MAXMAPSIZE]; //response
    char drawCom[MAXMAPSIZE];
    char delimit[] = "(),";
    int row;
    int col;
    int count;
    char initial[5]; //replace
    char UPletter[0];

    InitializeMap(DimArray, &MapSize);
    PrintInstructions();
    
    PrintMap(DimArray, MapSize);
    printf("\nEnter draw command (enter Q to quit) ");
    fgets(drawCom, MAXMAPSIZE-1, stdin);
    parse = strtok(drawCom, delimit);
    strcpy(letter, parse);
    UPletter[0] = toupper(letter[0]);

    while(drawCom[0] != 'Q')
    {
        parse = strtok(NULL, delimit);
        row = atoi(parse);
        parse = strtok(NULL, delimit);
        col = atoi(parse);
        parse = strtok(NULL, delimit);
        count = atoi(parse);
        parse = strtok(NULL, delimit);
        
        if (parse[0] == '\n')
        {
            (initial[0] = 'X');
        }
        else
        {
            strcpy(initial, parse);
        }
        
        
        if (UPletter[0] == 'P')
        {
            if (row > MapSize || col > MapSize || row < 0 || col < 0)
            {
                printf("\n\nThat draw command is out of range\n");
            }
            else
            {
                DimArray[row][col] = initial[0];
            }
        }
        
        else if (UPletter[0] == 'V')
        {
            if(row <= MapSize && col <= MapSize && row >= 0 && col >= 0 && count >= 0)
            {
                if (row + count > MapSize)
                {
                    printf("\n\nThat draw command is out of range\n");
                    count = MapSize - row;
                    DrawLine(DimArray, row, col, UPletter[0], count, initial[0]);
                }
                else
                {
                    DrawLine(DimArray, row, col, UPletter[0], count, initial[0]);
                }
            }
            else
            {
                printf("\n\nThat draw command is out of range\n");
            }
        }
        
        else if (UPletter[0] == 'H')
        {
            if (row <= MapSize && col <= MapSize && row >= 0 && col >= 0 && count >= 0)
            {
                if (col + count > MapSize)
                {
                    printf("\n\nThat draw command is out of range\n");
                    count = MapSize - col;
                    DrawLine(DimArray, row, col, UPletter[0], count, initial[0]);
                }
                else
                {
                    DrawLine(DimArray, row, col, UPletter[0], count, initial[0]);
                }
            }
            else
            {
                printf("\n\nThat draw command is out of range\n");
            }
        }
        
        else if (UPletter[0] != 'P' || UPletter[0] != 'V' || UPletter[0] != 'H')
        {
            printf("\n\nThat draw command is unknown\n");
        }
    
    PrintMap(DimArray, MapSize);
    printf("\nEnter draw command (enter Q to quit) ");
    fgets(drawCom, MAXMAPSIZE-1, stdin);
    parse = strtok(drawCom, delimit);
    strcpy(letter, parse);
    UPletter[0] = toupper(letter[0]);
    
    }
    
    return 0;
}
