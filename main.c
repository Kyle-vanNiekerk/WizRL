#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>>

#define mapLengthX 20
#define mapLengthY 80

/*
    ToDo:
    - Convert project to C++, Portable / C 88
    - Move character with keys
    - Screen Buffer
    - Map generation/read from file
    - Character stats/attributes (Health; Strength; Intelligence; Charisma; Luck)
    - Character needs (Hunger; Thirst; Sleep)
    - Character generation/read from file
    - Magic System (More focussed on ingredients than on player stats)
    - Maps: Walls; Floors; Furnature; Nature(Plants; Fire; Water);
    - NCURSES / SDL for input/colours
*/

struct playerCharacter {
    char symbol;
    int x;
    int y;
};

// Global Variables
char map[mapLengthY][mapLengthX];
char objects[mapLengthY][mapLengthX];
char creatures[mapLengthY][mapLengthX];
char walls[mapLengthY][mapLengthX];
char nature[mapLengthY][mapLengthX];

void drawMap(char map[mapLengthY][mapLengthX], char nature[mapLengthY][mapLengthX],
     char walls[mapLengthY][mapLengthX], char objects[mapLengthY][mapLengthX],
     char creatures[mapLengthY][mapLengthX]) {

    // Draw map Terrain -> objects -> creatures
    for (int i = 0; i < mapLengthX; i++)
    {
        for (int j = 0; j < mapLengthY; j++)
        {
            map[i][j] = nature[i][j];
            map[i][j] = walls[i][j];
            map[i][j] = objects[i][j];
            map[i][j] = creatures[i][j];
        }
    }

    // Draw the Map to the Terminal
    for (int y = 0; y < mapLengthX; y++)
    {
        for (int x = 0; x < mapLengthY; x++)
        {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    int running = 1;

    struct  playerCharacter testPlayer;
    testPlayer.symbol = '@';
    testPlayer.x = 10;
    testPlayer.y = 10;

    playerCharacter* playerPtr = &testPlayer;

    for (int i = 0; i < mapLengthX; i++)
    {
        for (int j = 0; j < mapLengthY; j++)
        {
            map[i][j] = '.';
            objects[i][j] = '.';
            creatures[i][j] = '.';
            walls[i][j] = '.';
            nature[i][j] = '.';
        }
    }

    creatures[testPlayer.x][testPlayer.y] = testPlayer.symbol;

    drawMap(map, nature, walls, objects, creatures);

    int inputKey = 0;
    while (running != 0)
    {
        inputKey = _getch();
        if (inputKey == 27)
            running = 0;

        switch (inputKey) {
        case 72:
            // code for arrow up
            //playerPtr-> y++;
            playerPtr->y--;
            break;
        case 80:
            // code for arrow down
            //playerPtr-> y--;
            playerPtr->y++;
            break;
        case 75:
            // code for arrow right
            //playerPtr->x++;
            playerPtr->x--;

            break;
        case 77:
            // code for arrow left
            //playerPtr-> x--;
            playerPtr->x++;
            break;
        }

        creatures[playerPtr-> x][playerPtr-> y] = playerPtr-> symbol;
        system("cls");
        drawMap(map, nature, walls, objects, creatures);
    }

    return 0;
}