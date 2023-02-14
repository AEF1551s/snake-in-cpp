#include "snake.h"

snake::snake(char *input[20][20])
{
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
}
void snake::spawn()
{
    body.push_front(display_p[7][8]);
    body.push_front(display_p[8][8]);

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
bool snake::grow(int direction, bool colision)
{
    char mode;
    if (colision)
        mode = body_char;
    else
        mode = fruit_char;

    switch (direction)
    {
    case 0:
        if (*(head - 20) == mode || (*(head - 20) == 'x' && *(head + 340) == mode))
            return true;
        return false;
    case 1:
        if (*(head + 20) == mode || (*(head + 20) == 'x' && *(head - 340) == mode))
            return true;
        return false;
    case 2:
        if (*(head - 1) == mode || (*(head - 1) == 'x' && *(head + 17) == mode))
            return true;
        return false;
    case 3:
        if (*(head + 1) == mode || (*(head + 1) == 'x' && *(head - 17) == mode))
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
bool snake::check_collision()
{
    return true;
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