#include "snake.h"

void snake::spawn()
{
    body.push_front(display_p[8][8]);
    body.push_front(display_p[7][8]);

    // update head and tail
    head = body.front();
    tail = body.back();
}
void snake::fruit(int r, int c)
{
    bool check = true;
    while (check)
    {
        if (*display_p[r][c] != body_char)
        {
            *display_p[r][c] = fruit_char;
            check = false;
        }
        else
        {
            check = true;
        }
    }
}
bool snake::grow(int direction)
{
    switch (direction)
    {
    case 0:
        if (*(head - 20) == fruit_char || (*(head - 20) == 'x' && *(head + 340) == fruit_char))
            return true;
        return false;
    case 1:
        if (*(head + 20) == fruit_char || (*(head + 20) == 'x' && *(head - 340) == fruit_char))
            return true;
        return false;
    case 2:
        if (*(head - 1) == fruit_char || (*(head - 1) == 'x' && *(head + 17) == fruit_char))
            return true;
        return false;
    case 3:
        if (*(head + 1) == fruit_char || (*(head + 1) == 'x' && *(head - 17) == fruit_char))
            return true;
        return false;
    default:
        return false;
    }
}
void snake::draw()
{
    for (std::list<char *>::iterator p = body.begin(); p != body.end(); p++)
        **p = body_char;
}
void snake::check_collision()
{
    //TODO: add collision
}
void snake::move(int direction, bool grow)
{
    switch (direction)
    {
    case 0:
        // up
        head = body.front();

        if (*(head - 20) == 'x')
            head += 340;
        else
            head -= 20;

        body.push_front(head);

        tail = body.back();
        if (!grow)
        {
            *tail = '.';
            body.pop_back();
        }

        break;
    case 1:

        // down
        head = body.front();

        if (*(head + 20) == 'x')
            // 17*20=340
            //. rindu skaits*platums
            head -= 340;
        else
            head += 20;

        body.push_front(head);

        tail = body.back();
        if (!grow)
        {
            *tail = '.';
            body.pop_back();
        }

        break;
    case 2:
        // left
        head = body.front();

        if (*(head - 1) == 'x')
            head += 17;
        else
            head--;

        body.push_front(head);

        tail = body.back();
        if (!grow)
        {
            *tail = '.';
            body.pop_back();
        }

        break;
    case 3:
        // right
        head = body.front();

        if (*(head + 1) == 'x')
            head -= 17;
        else
            head++;

        body.push_front(head);

        tail = body.back();
        if (!grow)
        {
            *tail = '.';
            body.pop_back();
        }

        break;
    default:
        break;
    }
}