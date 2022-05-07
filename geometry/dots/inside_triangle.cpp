#include<iostream>
#include<cmath>

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

double triangle_space(cord a, cord b, cord c)
{
    double side1, side2, side3;
    side1 = distance(a, b); side2 = distance(a, c); side3 = distance(b, c);
    
    double p = (side1 + side2 + side3) / 2;
    
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

bool is_inside(cord dot, cord a, cord b, cord c)
{
    double space1, space2;
    
    space1 = triangle_space(a, b, c);
    space2 = triangle_space(dot, b, c) + triangle_space(dot, a, c) + triangle_space(dot, a, b);
    
    return abs(space1 - space2) < 1e-6;
}

void read_arr(cord arr[], int &len)
{
    cin >> len;
    
    for(int i = 0; i < len; i++)
        cin >> arr[i].x >> arr[i].y;
}

int main()
{
    cord a, b, c, dots[100];
    int len, cnt = 0;
    
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    read_arr(dots, len);
    
    for (int i  = 0; i < len; i++)
        if (is_inside(dots[i], a, b, c)) cnt++;
    
    cout << cnt;
}
