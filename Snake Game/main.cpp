#include <iostream> 
#include <windows.h> // cls
#include <ctime>
#include "Snake.h"
#include "Movement.h"



int main() {
    Snake snake; 
    Movement movement; 

    srand(time(0)); // Seed only once 
    std::cout << "Press Q to quit\n";
    while (running) 
    {
        
        movement.handleInput(); 
        snake.update(); 
        snake.render(); 
        
        Sleep(100); // frame limiter
    }

    std::cout << "Game Over!\n";
}