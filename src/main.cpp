#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <conio.h>
#include <list>

#include "snake.h"

int time_scale = 100;

enum direction
{
    up,
    down,
    left,
    right,
    ni
};

void draw(char *display[20][20])
{
    std::string line0 = "";

    // convert array to single string
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            line0 = line0 + (*display[i][j]) + "  ";
        }
        line0 += "\n";
    }

    // output display array in string line
    std::cout << line0 << std::endl;
    // std::cout.flush();
    // time scale
    std::this_thread::sleep_for(std::chrono::milliseconds(time_scale));
    system("CLS");
}

void spawn_fruit(char *display[20][20], bool eaten)
{
    int randx = (rand() % (20 - 1) + 1);
    int randy = (rand() % (20 - 1) + 1);
    *display[randy][randx] = 'o';
    // add so fruit doesnt spawn on snake, that means that is cant also spawn in the same location again.
    // if snake has eaten fruit, spawn another; previous fruit was deleted by snake head.
}

direction kb_input()
{

    char input;

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

void display_fill(char *display[20][20])
{

    // draw display borders
    for (int i = 0; i < 20; i++)
    {
        *display[0][i] = 'x';
        *display[i][0] = 'x';
        *display[20 - 1][i] = 'x';
        *display[i][20 - 1] = 'x';
    }

    // display fill
    for (int i = 1; i < 20 - 1; i++)
    {
        for (int j = 1; j < 20 - 1; j++)
        {
            *display[i][j] = '.';
        }
    }
}

int main(void)
{
    char display[20][20];
    char *display_ptr[20][20];

    // initialize display_ptr
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            display_ptr[i][j] = &display[i][j];
        }
    }

    // initialize display with 'x' borders and '.' screen
    display_fill(display_ptr);

    // create object of class snake
    snake snake(display_ptr);
    snake.spawn();

    direction user_input = right;
    direction *user_input_ptr=&user_input;
    direction temp;
    // obligati

    while (1)
    {
        temp = kb_input();
        if (temp != ni)
        {
            *user_input_ptr = temp;
        }
        //TODO not allowed reverse movement

        

        std::cout << user_input << std::endl;

        draw(display_ptr);

        snake.move(user_input);

        snake.draw();
    }
}