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

//global clock = time_scale*2
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
    // std::this_thread::sleep_for(std::chrono::milliseconds(time_scale));
    // system("CLS");
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

    snake snake(display_p);

    std::ofstream file_in;
    std::ofstream* file_ptr=&file_in;
    file_in.open("score_log.txt");
    
    score score;

    // first fruit
    snake.fruit(rand() % 18 + 1, rand() % 18 + 1);

    snake.spawn();

    direction user_input = up;
    direction *user_input_p = &user_input;

    direction kb_user_input = ni;
    direction *kb_user_input_p = &kb_user_input;

    bool check_grow;
    
    while (true)
    {
        //TODO: not allow reverse movement
        //TODO: add highscores
        //TODO: add resume
        //TODO: add colision
        //TODO: add game over screen
        
        check_grow = snake.grow(*user_input_p);
        snake.move(*user_input_p, check_grow);
        if (check_grow){
            snake.fruit(rand() % 18 + 1, rand() % 18 + 1);
            score.inc();
        }


        //REMOVE WHEN DEBUGGING
        system("CLS");

        snake.draw();

        score.print();
        draw(display_p);

        std::this_thread::sleep_for(std::chrono::milliseconds(time_scale));

        *kb_user_input_p = kb_input();
        if (*kb_user_input_p != ni)
            *user_input_p = *kb_user_input_p;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(time_scale));
    }
}