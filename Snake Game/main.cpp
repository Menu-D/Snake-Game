#include <iostream> 
#include <conio.h>
#include <vector>
#include <utility> // std::pair
#include <windows.h> // cls
#include <cstdlib>
#include <ctime>

// --------- Global Variables ----------
bool running = true;


class Snake
{
public:
    std::vector<std::pair<int, int>> snake; // snake body
    int width = 20;
    int height = 10;
    int dx = 1;
    int dy = 0;
    
    struct Food
    {
        int x;
        int y;
    }food;

    Snake() {

        // initialize snake
        snake.push_back({ 3,5 });
        snake.push_back({ 4,5 });
        snake.push_back({ 5,5 });

        food.x = rand() % width;
        food.y = rand() % height;
    }

    void handleInput() {
        if (_kbhit()) { // only read input if a key was pressed
            char op = _getch();

            switch (op)
            {
            case 'Q': case 'q':
                running = false;
                break;
            case 'W': case 'w':
                if (dy == 0) { dx = 0; dy = -1; }
                break;
            case 'A': case 'a':
                if (dx == 0) { dx = -1; dy = 0; }
                break;
            case 'S': case 's':
                if (dy == 0) { dx = 0; dy = 1; }
                break;
            case 'D': case 'd':
                if (dx == 0) { dx = 1; dy = 0; }
                break;
            }
        }
    }

    void update() {
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

    void render() {
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
};

int main() {
    Snake ms;
    srand(time(0)); // Seed only once 
    std::cout << "Press Q to quit\n";
    while (running) {
        
        ms.handleInput();
        ms.update();
        ms.render();
        Sleep(100); // frame limiter
    }

    std::cout << "Game Over!\n";
}