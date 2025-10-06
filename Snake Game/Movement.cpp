#include "Movement.h"
#include "Snake.h"
#include <conio.h> 

Snake snakeMovement;

void Movement::handleInput() 
{

    if (_kbhit()) 
    { // only read input if a key was pressed
        char op = _getch();

        switch (op)
        {
        case 'Q': case 'q':
            running = false;
            break;
        case 'W': case 'w':
            if (snakeMovement.dy == 0) { snakeMovement.dx = 0; snakeMovement.dy = -1; }
            break;
        case 'A': case 'a':
            if (snakeMovement.dx == 0) { snakeMovement.dx = -1; snakeMovement.dy = 0; }
            break;
        case 'S': case 's':
            if (snakeMovement.dy == 0) { snakeMovement.dx = 0; snakeMovement.dy = 1; }
            break;
        case 'D': case 'd':
            if (snakeMovement.dx == 0) { snakeMovement.dx = 1; snakeMovement.dy = 0; }
            break;
        }
    }
}