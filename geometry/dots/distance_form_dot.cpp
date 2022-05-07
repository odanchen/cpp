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

cord find_intersect_point(cord A, cord B, cord C)
{
    double k, k2, b, b2;
    cord intersect_point;
    
    if (A.x == B.x)
    {
        intersect_point.x = A.x;
        intersect_point.y = C.y;
    }
    else if(A.y == B.y)
    {
        intersect_point.y = A.y;
        intersect_point.x = C.x;
    }
    else
    {
        k = (B.y - A.y) / (B.x - A.x);
        k2 = -1 / k;
        b = A.y - k * A.x;
        b2 = C.y - k2 * C.x;
        
        intersect_point.x = (b2 - b) / (k - k2);
        intersect_point.y = k * intersect_point.x + b;
    }
    
    return intersect_point;
}

double line_distance(cord A, cord B, cord C)
{
    cord intersect_point = find_intersect_point(A, B, C);
    
    return distance(C, intersect_point);
}

bool is_on_rays(cord A, cord B, cord intersect_point)
{
    return ((A.x <= B.x && intersect_point.x >= A.x) ||
            (A.x >= B.x && intersect_point.x <= A.x)) &&
            ((A.y <= B.y && intersect_point.y >= A.y) ||
            (A.y >= B.y && intersect_point.y <= A.y));
}

double ray_distance(cord A, cord B, cord C)
{
    
    cord intersect_point = find_intersect_point(A, B, C);
        
    if (is_on_rays(A, B, intersect_point))
        return distance(C, intersect_point);
    return distance(C, A);
}

bool in_cut(cord A, cord B, cord intersect_point)
{
    return (intersect_point.x >= min(A.x, B.x)) &&
           (intersect_point.x <= max(A.x, B.x)) &&
           (intersect_point.y >= min(A.y, B.y)) &&
           (intersect_point.y <= max(A.y, B.y));
}

double cut_distance(cord A, cord B, cord C)
{
    cord intersect_point = find_intersect_point(A, B, C);
        
    if (in_cut(A, B, intersect_point))
        return distance(C, intersect_point);
    if (is_on_rays(A, B, intersect_point))
        return distance(C, B);
    return distance(C, A);
}

int main()
{
    cord A, B, C;
    cin >> C.x >> C.y >> A.x >> A.y >> B.x >> B.y;
    
    cout << fixed << setprecision(6) << line_distance(A, B, C) << '\n';
    cout << fixed << setprecision(6) << ray_distance(A, B, C) << '\n';
    cout << fixed << setprecision(6) << cut_distance(A, B, C) << '\n';
}
