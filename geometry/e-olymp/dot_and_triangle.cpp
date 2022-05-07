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
    
    return fabs(space1 - space2) < 1e-8;
}

bool in_cut(cord A, cord B, cord intersect_point)
{
    double k, b;
    
    if (A.x != B.x)
    {
        k = (B.y - A.y) / (B.x - A.x);
        b = A.y - k * A.x;
        
        if (fabs((intersect_point.y) - (intersect_point.x * k + b)) < 1e-8)
            return (intersect_point.x >= min(A.x, B.x) - 1e-8) &&
                (intersect_point.x <= max(A.x, B.x) + 1e-8) &&
                (intersect_point.y >= min(A.y, B.y) - 1e-8) &&
                (intersect_point.y <= max(A.y, B.y) + 1e-8);
        return false;
    }
    
    return (intersect_point.x >= min(A.x, B.x) - 1e-8) &&
        (intersect_point.x <= max(A.x, B.x) + 1e-8) &&
        (intersect_point.y >= min(A.y, B.y) - 1e-8) &&
        (intersect_point.y <= max(A.y, B.y) + 1e-8);
}

int main()
{
    cord A, B, C, dot;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> dot.x >> dot.y;
    
    if (is_inside(dot, A, B, C))
    {
        if (in_cut(A, B, dot) || in_cut(B, C, dot) || in_cut(A, C, dot)) cout << "On";
        else cout << "In";
    }
    else cout << "Out";
}
