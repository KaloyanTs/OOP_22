#pragma once

struct Direction
{
    int dy, dx;
    Direction(unsigned d = 0)
    {
        if (d == 1)
        {
            dy = -1;
            dx = 0;
        }
        else if (d == 2)
        {
            dy = -1;
            dx = 1;
        }
        else if (d == 3)
        {
            dy = 0;
            dx = 1;
        }
        else if (d == 4)
        {
            dy = 1;
            dx = 1;
        }
        else if (d == 5)
        {
            dy = 1;
            dx = 0;
        }
        else if (d == 6)
        {
            dy = 1;
            dx = -1;
        }
        else if (d == 7)
        {
            dy = 0;
            dx = -1;
        }
        else if (d == 8)
        {
            dy = -1;
            dx = -1;
        }
        else
        {
            dx = dy = 0;
        }
    }
};