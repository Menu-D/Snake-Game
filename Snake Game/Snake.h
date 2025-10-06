#pragma once
#include <vector> 

extern bool running = true;

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

