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

int main()
{
    cord dot1, dot2;
    cin >> dot1.x >> dot1.y >> dot2.x >> dot2.y;
    cout << fixed << setprecision(3) << distance(dot1, dot2);
}
