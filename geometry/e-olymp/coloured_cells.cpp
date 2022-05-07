#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

double sqr(double num)
{
    return num * num;
}

int count_cells(double cell_size, double rad)
{
    int cnt = 0;
    double cell_rad = rad / cell_size;
    
    for (double x = 0; x < cell_rad; x++)
    {
        if (sqr(cell_rad) - sqr(x + 1) >= 0)
            cnt += (ceil(sqrt(sqr(cell_rad) - sqr(x))) - floor(sqrt(sqr(cell_rad) - sqr(x + 1))));
        else
            cnt += ceil(sqrt(sqr(cell_rad) - sqr(x)));
    }
    
    if (cnt == 0) return 4;
    return cnt * 4;
}

int main()
{
    double cell_size, rad;
    cin >> cell_size >> rad;
        
    cout << count_cells(cell_size, rad);
}
