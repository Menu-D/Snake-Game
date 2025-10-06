#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include <vector> 

extern bool running;

class Snake
{
public: 

    static int width;
    static int height;
    static int dx;
    static int dy;

    std::vector<std::pair<int, int>> snake; // snake body

    struct Food
    {
        int x;
        int y;
    };

    Food food; 

    Snake(); 
    void update(); 
    void render(); 

};

#endif
