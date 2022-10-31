#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <chrono>
#include <thread>
// using std::cout;
#define size_x 20
#define size_y 20

void draw(char *display[20][20])
{
    // time in miliseconds
    int time_scale = 250;

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

    // delay 50ms
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(time_scale));
    system("CLS");
}

/*
TODO add fruit spawn logic
TODO add keyboard inputs
TODO add snake movement logic, passtrough borders
TODO snake lenght changes, eating
*/
int main(void)
{
    char display[size_y][size_x];
    char *display_ptr[size_y][size_x];
    int display_size = sizeof(display) / sizeof(display[0]);

    // initialize display_ptr
    for (int i = 0; i < display_size; i++)
    {
        for (int j = 0; j < display_size; j++)
        {
            display_ptr[i][j] = &display[i][j];
        }
    }

    // draw display borders
    for (int i = 0; i < size_y; i++)
    {
        *display_ptr[0][i] = 'x';
        *display_ptr[i][0] = 'x';
        *display_ptr[size_y - 1][i] = 'x';
        *display_ptr[i][size_x - 1] = 'x';
    }

    // display fill
    for (int i = 1; i < display_size - 1; i++)
    {
        for (int j = 1; j < display_size - 1; j++)
        {
            *display_ptr[i][j] = '.';
        }
    }
    int i = 0;
    while (1)
    {
        std::cout << "frame: " << i++ << std::endl;
        draw(display_ptr);
    }
}