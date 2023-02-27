#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <list>
#include <vector>
#include <time.h>
#include <stdlib.h>

class snake
{
private:
    bool seeded = false;
    std::list<char *> body;
    char *head;
    char *tail;
    char *display_p[20][20];
    std::vector<char *> fruit_table;
    char body_char = 'o';
    char fruit_char = '@';

public:
    snake(char *input[20][20], bool seeded);
    void init_fruit_table();
    void spawn();
    void fruit();
    bool check_mode(int direction, bool colision_mode);
    void draw();
    void move(int direction, bool grow);
};

#endif