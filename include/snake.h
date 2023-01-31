#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <list>

class snake
{
private:
    std::list<char *> body;
    char *display_ptr[20][20];


public:
    snake(char *input[20][20])
    {
        // add display array so class knows address of every location
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                display_ptr[i][j] = input[i][j];
            }
        }
    }
    void spawn();
    void grow();
    void draw();
    void check_collision();
    void move(int direction);
};

#endif