#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <list>

class snake
{
private:
    std::list<char *> body;
    char *head;
    char *tail;
    char *display_p[20][20];
    char body_char = 'o';
    char fruit_char = '@';

public:
    snake(char *input[20][20])
    {
        // add display array so class knows address of every location
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                display_p[i][j] = input[i][j];
            }
        }
    }
    void spawn();
    void fruit(int r, int c);
    bool grow(int direction);
    void draw();
    void check_collision();
    void move(int direction, bool grow);
};

#endif