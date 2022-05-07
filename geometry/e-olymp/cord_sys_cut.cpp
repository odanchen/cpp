#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

struct cord
{
    int x;
    int y;
};

int find_quarter(cord dot)
{
    if ((dot.x > 0) && (dot.y > 0)) return 1;
    if ((dot.x < 0) && (dot.y > 0)) return 2;
    if ((dot.x < 0) && (dot.y < 0)) return 3;
    if ((dot.x > 0) && (dot.y < 0)) return 4;
    
    return 0;
}

void mark_quarters(cord cut_start, cord cut_finish, bool quarters[])
{
    if ((cut_start.x == cut_finish.x && cut_start.x == 0) || (cut_start.y == cut_finish.y && cut_start.y == 0))
    {
        quarters[0] = true; return;
    }
    
    if (cut_start.x == 0 && cut_start.y == 0)
    {
        quarters[find_quarter(cut_finish)] = true; return;
    }
    if (cut_finish.x == 0 && cut_finish.y == 0)
    {
        quarters[find_quarter(cut_start)] = true; return;
    }
    
    if (cut_start.x == 0 && cut_start.y > 0)
    {
        if ((cut_finish.y == 0 && cut_finish.x > 0) || find_quarter(cut_finish) == 1)
        {
            quarters[1] = true; return;
        }
        if ((cut_finish.y == 0 && cut_finish.x < 0) || find_quarter(cut_finish) == 2)
        {
            quarters[2] = true; return;
        }
        if (find_quarter(cut_finish) == 3)
        {
            quarters[2] = true; quarters[3] = true; return;
        }
        if (find_quarter(cut_finish) == 4)
        {
            quarters[4] = true; quarters[1] = true; return;
        }
    }
    if (cut_start.y == 0 && cut_start.x > 0)
    {
        if ((cut_finish.x == 0 && cut_finish.y > 0) || find_quarter(cut_finish) == 1)
        {
            quarters[1] = true; return;
        }
        if ((cut_finish.x == 0 && cut_finish.y < 0) || find_quarter(cut_finish) == 4)
        {
            quarters[4] = true; return;
        }
        if (find_quarter(cut_finish) == 2)
        {
            quarters[1] = true; quarters[2] = true; return;
        }
        if (find_quarter(cut_finish) == 3)
        {
            quarters[4] = true; quarters[3] = true; return;
        }
    }
    if (cut_start.x == 0 && cut_start.y < 0)
    {
        if ((cut_finish.y == 0 && cut_finish.x > 0) || find_quarter(cut_finish) == 4)
        {
            quarters[4] = true; return;
        }
        if ((cut_finish.y == 0 && cut_finish.x < 0) || find_quarter(cut_finish) == 3)
        {
            quarters[3] = true; return;
        }
        if (find_quarter(cut_finish) == 1)
        {
            quarters[1] = true; quarters[4] = true; return;
        }
        if (find_quarter(cut_finish) == 2)
        {
            quarters[3] = true; quarters[2] = true; return;
        }
    }
    if (cut_start.y == 0 && cut_start.x < 0)
    {
        if ((cut_finish.x == 0 && cut_finish.y > 0) || find_quarter(cut_finish) == 2)
        {
            quarters[2] = true; return;
        }
        if ((cut_finish.x == 0 && cut_finish.y < 0) || find_quarter(cut_finish) == 3)
        {
            quarters[3] = true; return;
        }
        if (find_quarter(cut_finish) == 1)
        {
            quarters[1] = true; quarters[2] = true; return;
        }
        if (find_quarter(cut_finish) == 4)
        {
            quarters[4] = true; quarters[3] = true; return;
        }
    }
    
    if (cut_finish.x == 0 && cut_finish.y > 0)
    {
        if ((cut_start.y == 0 && cut_start.x > 0) || find_quarter(cut_start) == 1)
        {
            quarters[1] = true; return;
        }
        if ((cut_start.y == 0 && cut_start.x < 0) || find_quarter(cut_start) == 2)
        {
            quarters[2] = true; return;
        }
        if (find_quarter(cut_start) == 3)
        {
            quarters[2] = true; quarters[3] = true; return;
        }
        if (find_quarter(cut_start) == 4)
        {
            quarters[4] = true; quarters[1] = true; return;
        }
    }
    if (cut_finish.y == 0 && cut_finish.x > 0)
    {
        if ((cut_start.x == 0 && cut_start.y > 0) || find_quarter(cut_start) == 1)
        {
            quarters[1] = true; return;
        }
        if ((cut_start.x == 0 && cut_start.y < 0) || find_quarter(cut_start) == 4)
        {
            quarters[4] = true; return;
        }
        if (find_quarter(cut_start) == 2)
        {
            quarters[1] = true; quarters[2] = true; return;
        }
        if (find_quarter(cut_start) == 3)
        {
            quarters[4] = true; quarters[3] = true; return;
        }
    }
    if (cut_finish.x == 0 && cut_finish.y < 0)
    {
        if ((cut_start.y == 0 && cut_start.x > 0) || find_quarter(cut_start) == 4)
        {
            quarters[4] = true; return;
        }
        if ((cut_start.y == 0 && cut_start.x < 0) || find_quarter(cut_start) == 3)
        {
            quarters[3] = true; return;
        }
        if (find_quarter(cut_start) == 1)
        {
            quarters[1] = true; quarters[4] = true; return;
        }
        if (find_quarter(cut_start) == 2)
        {
            quarters[3] = true; quarters[2] = true; return;
        }
    }
    if (cut_finish.y == 0 && cut_start.x < 0)
    {
        if ((cut_start.x == 0 && cut_start.y > 0) || find_quarter(cut_start) == 2)
        {
            quarters[2] = true; return;
        }
        if ((cut_start.x == 0 && cut_start.y < 0) || find_quarter(cut_start) == 3)
        {
            quarters[3] = true; return;
        }
        if (find_quarter(cut_start) == 1)
        {
            quarters[1] = true; quarters[2] = true; return;
        }
        if (find_quarter(cut_start) == 4)
        {
            quarters[4] = true; quarters[3] = true; return;
        }
    }

    
    if ((find_quarter(cut_start) == 1 && find_quarter(cut_finish) == 3) ||
        (find_quarter(cut_start) == 3 && find_quarter(cut_finish) == 1))
    {
        double k, b;
        k = (double)(cut_start.y - cut_finish.y) / (double)(cut_start.x - cut_finish.x);
        b = cut_start.y - cut_start.x * k;
        if (b == 0)
        {
            quarters[1] = true; quarters[3] = true; return;
        }
        if (-b / k > 0)
        {
            quarters[1] = true; quarters[3] = true; quarters[4] = true; return;
        }
        quarters[1] = true; quarters[3] = true; quarters[2] = true; return;
    }
        
    if ((find_quarter(cut_start) == 2 && find_quarter(cut_finish) == 4) ||
        (find_quarter(cut_start) == 4 && find_quarter(cut_finish) == 2))
    {
        double k, b;
        k = (double)(cut_start.y - cut_finish.y) / (double)(cut_start.x - cut_finish.x);
        b = cut_start.y - cut_start.x * k;
        if (b == 0)
        {
            quarters[2] = true; quarters[4] = true; return;
        }
        if (b > 0)
        {
            quarters[2] = true; quarters[1] = true; quarters[4] = true; return;
        }
        quarters[2] = true; quarters[3] = true; quarters[4] = true; return;
    }
    
    quarters[find_quarter(cut_start)] = true;
    quarters[find_quarter(cut_finish)] = true;
}

int main()
{
    cord cut_start, cut_finish;
    bool quarters[5] = {0};
    
    cin >> cut_start.x >> cut_start.y >> cut_finish.x >> cut_finish.y;
    
    mark_quarters(cut_start, cut_finish, quarters);
    
    for (int i = 0; i <= 4; i++)
        if (quarters[i]) cout << i << '\n';
}
