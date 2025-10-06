# Snake game in Console 

This is a very basic concept of a snake game in the console using C++. This project like all my others were not my own unique idea as this was all done purely as a learing attempt. 

# How the game works?

This snake game works by displaying a set of coordinates on a 2d grid with the head being at the end of the list. Each frame displayed reads the players input WASD and updates the snakes direction and calculates the new head position, it adds to the list and removes the tail unless the snake has just eaten food (so each time you move up, down, left or right the tail gets removed to show that the snake has moved in that specific direction, however the tail does not get removed if the snake has eaten food). Food in this game is randomly placed in a certain coordinate that when eaten by the snake it causes it to grow. The simple grid is rendered in the console with symbols for the snake, food, head and empty space. The game loop repeats the process until the snake has hit a wall or if the player quits. 

# Rendering 

The grid is built with . for empty space.
Snake’s head = @
Snake’s body = o
Food = *
Display is cleared (system("cls")) each frame and redrawn.

# Game loop 

Handle input (WASD or Q to quit).
Update snake’s position.
Check collision (walls, food).
Render the grid.
Delay (Sleep(100)) for consistent speed.

# Controls

simple controls such as WASD 
W - up 
A - right 
S - down 
D - left 

# What the game looks like 

<img src = "https://github.com/user-attachments/assets/4a1f6040-bda8-4e85-a8f3-1a1de68dee08" width = "150" />

<img src= "https://github.com/user-attachments/assets/d582d81a-bc6a-4318-870c-eede420f70e2" width = "150" />

Its not the best but it was purely for my own learning purposes!
