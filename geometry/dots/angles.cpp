#include<bits/stdc++.h>

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

double find_angle(double main, double b, double c)
{
    return acos((sqr(b) + sqr(c) - sqr(main)) / (2 * b * c)) * 180 / 3.14159265359;
}

int main()
{
    double sides[3];
    cord node_a, node_b, node_c;
    cin >> node_a.x >> node_a.y >> node_b.x >> node_b.y >> node_c.x >> node_c.y;
    
    sides[0] = distance(node_b, node_c);
    sides[1] = distance(node_a, node_c);
    sides[2] = distance(node_a, node_b);
    
    sort(sides, sides + 3);

    cout << fixed << setprecision(6) << find_angle(sides[2], sides[1], sides[0]);
}
