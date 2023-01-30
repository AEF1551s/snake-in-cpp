#include "snake.h"

void snake::spawn()
{
    // body.push_front(display_ptr[rand() % 18 + 1][rand() % 18 + 1]);
    body.push_front(display_ptr[8][8]);
    body.push_front(display_ptr[7][8]);
}
void snake::grow()
{
    // check if next move is on fruit.
    // if so then fruit become part of snake
}
void snake::draw()
{
    for (std::list<char *>::iterator ptr = body.begin(); ptr != body.end(); ptr++)
        **ptr = 'o';
}
void snake::check_collision()
{
    // check collision
}
void snake::move()
{
    // can move down/up only if already is moving left/right
    // can move left/rifht if only is moving down/up
    // all others are not allowed, for example, if moving up, cannot move down.

    char *head;
    char *tail;

    // right
    // head = body.front();

    // if (*(head + 1) == 'x')
    //     head -= 17;
    // else
    //     head++;

    // body.push_front(head);

    // tail = body.back();
    // *tail = '.';

    // body.pop_back();

    // left
    //  head = body.front();

    // if (*(head - 1) == 'x')
    //     head += 17;
    // else
    //     head--;

    // body.push_front(head);

    // tail = body.back();
    // *tail = '.';

    // body.pop_back();

    // down
    // head = body.front();

    // if (*(head + 20) == 'x')
    // //17*20=340
    // //. rindu skaits*platums
    //     head -= 340;
    // else
    //     head+=20;

    // body.push_front(head);

    // tail = body.back();
    // *tail = '.';

    // body.pop_back();

    // up
    head = body.front();

    if (*(head - 20) == 'x')
        head += 340;
    else
        head -= 20;

    body.push_front(head);

    tail = body.back();
    *tail = '.';

    body.pop_back();
}