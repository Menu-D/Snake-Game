#include "Snake.h"
#include <string> 
#include <iostream> 

bool running = true; 

int Snake::width = 40; 
int Snake::height = 20; 
int Snake::dx = 1; 
int Snake::dy = 0; 

Snake::Snake() 
{

    // initialize snake
    snake.push_back({ 3,5 });
    snake.push_back({ 4,5 });
    snake.push_back({ 5,5 });

    food.x = rand() % width;
    food.y = rand() % height;
}

void Snake::update()
{
    auto head = snake.back(); // current head
    int newx = head.first + dx;
    int newy = head.second + dy;


    // bounds checking
    if (newx < 0 || newx >= width || newy < 0 || newy >= height) {
        running = false; // snake hit wall
        return;
    }

    // move snake
    snake.push_back({ newx, newy });

    // check food
    if (newx == food.x && newy == food.y) {
        // optional: spawn new food here
        food.x = rand() % width;
        food.y = rand() % height;
    }
    else {
        snake.erase(snake.begin()); // This removes the tail each time the snake eats food 
    }
}

void Snake::render() {
    // create empty grid
    std::vector<std::string> grid(height, std::string(width, '.'));


    // draw food
    grid[food.y][food.x] = '*';

    // draw snake body
    for (int i = 0; i < snake.size() - 1; i++) {
        int x = snake[i].first;
        int y = snake[i].second;
        grid[y][x] = 'o';
    }

    // draw snake head
    auto head = snake.back();
    grid[head.second][head.first] = '@';

    // clear screen and print
    system("cls");
    for (auto row : grid) {
        std::cout << row << "\n";
    }
}