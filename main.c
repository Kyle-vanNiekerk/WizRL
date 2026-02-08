#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define rows 20
#define cols 100

struct playerCharacter {
    char symbol;
    int row;
    int col;
};

struct map {
    char nature[rows][cols];
    char buildings[rows][cols];
    char objects[rows][cols];
    char creatures[rows][cols];
    char result[rows][cols];
};

void drawMap(struct map* myMap) {
    char offScreenBuffer[rows][cols];
    // Draw map Terrain -> Objects -> Creatures into the off-screen buffer
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            myMap->result[i][j] = myMap->nature[i][j];
            myMap->result[i][j] = myMap->buildings[i][j];
            myMap->result[i][j] = myMap->objects[i][j];
            myMap->result[i][j] = myMap->creatures[i][j];
            offScreenBuffer[i][j] = myMap->result[i][j];
        }
    }

    // Draw the Map to the Terminal/Buffer
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            mvaddch(y, x, offScreenBuffer[y][x]);
        }
    }
    refresh();
}

int main()
{
    struct playerCharacter testPlayer;
    struct playerCharacter* playerPtr = &testPlayer;
    playerPtr->symbol = '@';
    playerPtr->row = 0;
    playerPtr->col = 0;

    struct map gameMap;
    struct map* testMap = &gameMap;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            testMap->objects[i][j] = ' ';
            testMap->creatures[i][j] = ' ';
            testMap->buildings[i][j] = ' ';
            testMap->nature[i][j] = ' ';
        }
    }

    char prevPos = gameMap.creatures[testPlayer.row][testPlayer.col];

    testMap->creatures[testPlayer.row][testPlayer.col] = testPlayer.symbol;

    // Initialize ncurses
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    drawMap(testMap);

    int running = 1;
    int inputKey = 0;

    // Directional Movement
    while (running != 0)
    {
        testMap->creatures[testPlayer.row][testPlayer.col] = prevPos;

        inputKey = getch();
        if (inputKey == 27) // esc
            running = 0;

        switch (inputKey) {
        case KEY_UP:
            if (playerPtr->row != 0)
            {
                playerPtr->row--;
            }
            break;
        case KEY_DOWN:
            if (playerPtr->row < rows - 1)
            {
                playerPtr->row++;
            }
            break;
        case KEY_LEFT:
            if (playerPtr->col != 0)
            {
                playerPtr->col--;
            }
            break;
        case KEY_RIGHT:
            if (playerPtr->col < cols - 1)
            {
                playerPtr->col++;
            }
            break;
        }

        testMap->creatures[testPlayer.row][testPlayer.col] = testPlayer.symbol;
        drawMap(testMap);
    }

    // End ncurses
    endwin();

    return 0;
}
