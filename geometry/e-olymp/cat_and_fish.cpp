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

bool is_on_rays(cord A, cord B, cord intersect_point)
{
    return ((A.x <= B.x && intersect_point.x >= A.x) ||
            (A.x >= B.x && intersect_point.x <= A.x)) &&
            ((A.y <= B.y && intersect_point.y >= A.y) ||
            (A.y >= B.y && intersect_point.y <= A.y));
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

void read_arr(cord arr[], int len)
{
    for (int i = 0; i < len * 2; i++)
        cin >> arr[i].x >> arr[i].y;
}

int main()
{
    int cnt = 0, hunger, day, reachable = 0, rad;
    cord dots[500], tree;
    tree.x = 0; tree.y = 0;
    
    cin >> rad >> cnt >> hunger;
    read_arr(dots, cnt);
    
    for (int i = 0; i < cnt * 2; i += 2)
        if (cut_distance(dots[i], dots[i + 1], tree) <= rad + 1e-8) reachable++;
    
    day = reachable / hunger + 1;
    
    cout << day;
}
