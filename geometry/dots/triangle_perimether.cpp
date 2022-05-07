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

void read_arr(cord arr[], int &len)
{
    cin >> len;
    
    for (int i = 0; i < len; i++)
        cin >> arr[i].x >> arr[i].y;
}

int main()
{
    cord side1, side2, side3;
    cin >> side1.x >> side1.y >> side2.x >> side2.y >> side3.x >> side3.y;
    double ans = distance(side1, side2) + distance(side1, side3) + distance(side2, side3);
    cout << fixed << setprecision(3) << ans;
}
