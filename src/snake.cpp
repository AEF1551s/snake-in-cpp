#include "snake.h"

snake::snake(char *input[20][20], bool seeded)
{
    // add display array so class knows address of every location
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            display_p[i][j] = input[i][j];
        }
    }

    // rand seed
    if (!seeded)
    {
        srand(time(NULL));
        seeded = true;
    }
}
void snake::spawn()
{
    body.push_front(display_p[1][1]);
    body.push_front(display_p[1][2]);
    // body.push_front(display_p[7][8]);
    // body.push_front(display_p[8][8]);

    // update head and tail
    head = body.front();
    tail = body.back();
}
void snake::init_fruit_table()
{
    fruit_table.clear();

    for (int i = 1; i < 20 - 1; i++)
    {
        for (int j = 1; j < 20 - 1; j++)
        {
            if (*display_p[i][j] != 'x' && *display_p[i][j] != body_char)
            {
                fruit_table.push_back(display_p[i][j]);
            }
        }
    }
}

void snake::fruit()
{
    init_fruit_table();
    int size = fruit_table.size();
    int ran_int = rand() % size;
    *fruit_table.at(ran_int) = '@';
}
bool snake::check_mode(int direction, bool colision_mode)
{
    char mode;
    if (colision_mode)
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