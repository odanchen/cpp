#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

struct cord
{
    double x;
    double y;
};

double sqr(double num)
{
    return num * num;
}

double distance(cord dot1, cord dot2)
{
    return sqrt(sqr(dot1.x - dot2.x) + sqr(dot1.y - dot2.y));
}

bool in_circle(cord centre, cord dot, int rad)
{
    return (distance(dot, centre) <= rad + 1e-8);
}

int main()
{
    int cnt = 0;
    int rad;
    cin >> rad;
    
    for (int row = 1; row <= rad; row++)
        cnt += trunc(sqrt(sqr(rad) - sqr(row))) + 1;
    
    cout << cnt * 4 + 1;
}
