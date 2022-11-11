#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <conio.h>

#define size_x 20
#define size_y 20

/*
class or struct snake to store snake head, tail and list for snake
*/

/*
TODO
Change time_scale to a global clock
*/
int time_scale=500;

enum direction {up, down, left, right, ni};

void draw(char *display[20][20]){
    std::string line0 = "";

    // convert array to single string
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            line0 = line0 + (*display[i][j]) + "  ";
        }
        line0 += "\n";
    }

    // output display array in string line0
    std::cout << line0 << std::endl;
    // time scale
    std::this_thread::sleep_for(std::chrono::milliseconds(time_scale));
    system("CLS");
    std::cout.flush();
}

void spawn_fruit(char *display[20][20], bool eaten)
{
    int randx = (rand() % (size_x - 1) + 1);
    int randy = (rand() % (size_y - 1) + 1);
    *display[randy][randx] = 'o';
    // add so fruit doesnt spawn on snake, that means that is cant also spawn in the same location again.
    // if snake has eaten fruit, spawn another; previous fruit was deleted by snake head.
}

direction kb_input(){
    char input='0';

    if (_kbhit())
    {
       input = (char)_getch();
    }

    switch (input)
    {
    case 'w':
        return up;

    case 's':
        return down;

    case 'a':
        return left;

    case 'd':
        return right;

    default:
        return ni;
    } 
}

void snake(direction dirctn){
    /*
    snake gets directions, then moves. if snake has eaten a fruit then snake lenght++.
    if snake crashes into itself then game over, return some value
    move snake trough borders
    */
}

void display_fill(char *display[20][20]){

    // draw display borders
    for (int i = 0; i < size_y; i++)
    {
        *display[0][i] = 'x';
        *display[i][0] = 'x';
        *display[size_y - 1][i] = 'x';
        *display[i][size_y - 1] = 'x';
    }

    // display fill
    for (int i = 1; i < size_y - 1; i++)
    {
        for (int j = 1; j < size_x - 1; j++)
        {
            *display[i][j] = '.';
        }
    }
}

int main(void)
{
    char display[size_y][size_x];
    char *display_ptr[size_y][size_x];

    // initialize display_ptr
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            display_ptr[i][j] = &display[i][j];
        }
    }

    int i = 0;
    // initialize display with 'x' borders and '.' screen
    display_fill(display_ptr);

    while (1)
    {
        // std::cout << "frame: " << i++ << std::endl;
        std::cout << kb_input() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time_scale));
        // draw(display_ptr);

    }
}