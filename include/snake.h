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
    snake(char *input[20][20]);
    void spawn();
    void fruit(int r, int c);
    bool grow(int direction, bool colision);
    void draw();
    void move(int direction, bool grow);
};

#endif