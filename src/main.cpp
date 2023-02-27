#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <conio.h>
#include <list>
#include <time.h>
#include <fstream>

#include "snake.h"
#include "score.h"

// global clock = time_scale*2
int time_scale = 100;

//TODO: ADD INPUT CLASS
//TODO: ADD DISPLAY CLASS
enum direction
{
    up,
    down,
    left,
    right,
    ni,
    quit,
    reset_score,
    pause
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

    std::cout << line0;
    std::cout.flush();
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
    case 'x':
        return quit;
    case 'r':
        return reset_score;
    case 'p':
        return pause;
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
    // random seed
    srand(time(NULL));

    char display[20][20];
    char *display_p[20][20];

    // initialize display_p
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            display_p[i][j] = &display[i][j];
        }
    }

    // initialize display with 'x' borders and '.' screen
    display_fill(display_p);

    snake snake(display_p, false);

    std::ofstream file_in;
    std::ifstream file_out;
    score score(file_in, file_out);

    snake.spawn();

    // first fruit
    snake.fruit();

    direction user_input = up;
    direction *user_input_p = &user_input;

    direction prev_user_input = up;
    direction *prev_user_input_p = &prev_user_input;

    direction kb_user_input = ni;
    direction *kb_user_input_p = &kb_user_input;

    bool check_grow;
    while (true)
    {
        check_grow = snake.check_mode(*user_input_p, false);
        snake.move(*user_input_p, check_grow);
        if (check_grow)
        {
            snake.fruit();
            score.inc();
            time_scale -= 2;
        }

        // REMOVE WHEN DEBUGGING
        system("CLS");

        snake.draw();
        score.print();
        draw(display_p);

        std::this_thread::sleep_for(std::chrono::milliseconds(time_scale));

        *kb_user_input_p = kb_input();

        if (*kb_user_input_p != ni)
        {
            if (*kb_user_input_p + *user_input_p == 1 || *kb_user_input_p + *user_input_p == 5)
            {
                // do nothing
            }
            else
            {
                *prev_user_input_p = *user_input_p;
                *user_input_p = *kb_user_input_p;
                *user_input_p = *user_input_p;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(time_scale));

        if (snake.check_mode(*user_input_p, true))
        {
            std::cout << "GAME OVER" << std::endl;
            break;
        }

        if (*user_input_p == quit)
            break;

        if (*user_input_p == reset_score)
        {
            score.reset();
            *user_input_p = *prev_user_input_p;
        }
        // if user input is pause, move and grow methods do nothing, but everything else prints the static display.
    }
    score.save();
}