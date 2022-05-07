#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

const double Pi = 3.141592653;

struct cord
{
    double x;
    double y;
};


int main()
{
    int cnt, side = 1;
    double left_corner = -(1/2.0);
    cord last_top;
    cin >> cnt;
    
    for (int i = 0; i < cnt - 1; i++)
    {
        left_corner += side;
        side += 2;
    }
    
    last_top.x = left_corner +  side / 2.0;
    last_top.y = side * cos(Pi / 6);
    
    cout << fixed << setprecision(3) << last_top.x << ' ' << last_top.y;
}
