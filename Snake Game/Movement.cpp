#include "Movement.h"
#include "Snake.h"
#include <conio.h> 

Snake snake; 

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
            if (snake.dy == 0) { snake.dx = 0; snake.dy = -1; }
            break;
        case 'A': case 'a':
            if (snake.dx == 0) { snake.dx = -1; snake.dy = 0; }
            break;
        case 'S': case 's':
            if (snake.dy == 0) { snake.dx = 0; snake.dy = 1; }
            break;
        case 'D': case 'd':
            if (snake.dx == 0) { snake.dx = 1; snake.dy = 0; }
            break;
        }
    }
}