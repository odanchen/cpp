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

bool is_on_segments(cord cut_1_start, cord cut_1_finish, cord cut_2_start, cord cut_2_finish, cord intersect_point)
{
    return (intersect_point.x <= max(cut_1_start.x, cut_1_finish.x) + 1e-7) &&
           (intersect_point.x >= min(cut_1_start.x, cut_1_finish.x) - 1e-7) &&
           (intersect_point.x <= max(cut_2_start.x, cut_2_finish.x) + 1e-7) &&
           (intersect_point.x >= min(cut_2_start.x, cut_2_finish.x) - 1e-7) &&
           (intersect_point.y <= max(cut_1_start.y, cut_1_finish.y) + 1e-7) &&
           (intersect_point.y >= min(cut_1_start.y, cut_1_finish.y) - 1e-7) &&
           (intersect_point.y <= max(cut_2_start.y, cut_2_finish.y) + 1e-7) &&
           (intersect_point.y >= min(cut_2_start.y, cut_2_finish.y) - 1e-7);
}

bool is_paralel(double k1, double k2)
{
    return fabs(k1 - k2) < 1e-6;
}

bool is_equal(double num1, double num2)
{
    return fabs(num1 - num2) < 1e-7;
}

bool parallel_case(cord cut_1_start, cord cut_1_finish, cord cut_2_start, cord cut_2_finish)
{
    double k1 = (cut_1_start.y - cut_1_finish.y) / (cut_1_start.x - cut_1_finish.x);
    double k2 = (cut_2_start.y - cut_2_finish.y) / (cut_2_start.x - cut_2_finish.x);
    double b1 = cut_1_start.y - cut_1_start.x * k1;
    double b2 = cut_2_start.y - cut_2_start.x * k2;
    
    if (not(is_equal(b1, b2))) return false;
    
    return is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, cut_1_start) ||
    is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, cut_2_start) ||
    is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, cut_1_finish) ||
    is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, cut_2_finish);
}

bool vertical_case(cord cut_1_start, cord cut_1_finish, cord cut_2_start, cord cut_2_finish)
{
    if (is_equal(cut_1_finish.x, cut_1_start.x) && is_equal(cut_2_finish.x, cut_2_start.x))
    {
        if (not(is_equal(cut_1_finish.x, cut_2_finish.x))) return false;
        
        return is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, cut_1_start) ||
        is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, cut_2_start) ||
        is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, cut_1_finish) ||
        is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, cut_2_finish);
    }
    
    double k1, k2, b1, b2;
    cord intersect_point;
    
    if (cut_1_start.x == cut_1_finish.x)
    {
        k2 = (cut_2_start.y - cut_2_finish.y) / (cut_2_start.x - cut_2_finish.x);
        b2 = cut_2_start.y - cut_2_start.x * k2;
        if (k2 == 0)
        {
            intersect_point.x = cut_1_start.x; intersect_point.y = cut_2_start.y;
            return is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, intersect_point);
        }
        intersect_point.y = k2 * cut_1_start.x + b2; intersect_point.x = cut_1_start.x;
    }
    
    else
    {
        k1 = (cut_1_start.y - cut_1_finish.y) / (cut_1_start.x - cut_1_finish.x);
        b1 = cut_1_start.y - cut_1_start.x * k1;
        if (k1 == 0)
        {
            intersect_point.y = cut_1_start.y; intersect_point.x = cut_2_start.x;
            return is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, intersect_point);
        }
        intersect_point.y = k1 * cut_2_start.x + b1; intersect_point.x = cut_2_start.x;
    }
    
    return is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, intersect_point);
}

bool is_intersecting(cord cut_1_start, cord cut_1_finish, cord cut_2_start, cord cut_2_finish)
{
    cord intersect_point;
    double k1, k2, b1, b2;
    
    if (abs(cut_1_finish.x - cut_1_start.x) < 1e-7 || abs(cut_2_finish.x - cut_2_start.x) < 1e-7)
        return vertical_case(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish);
    
    k1 = (cut_1_start.y - cut_1_finish.y) / (cut_1_start.x - cut_1_finish.x);
    k2 = (cut_2_start.y - cut_2_finish.y) / (cut_2_start.x - cut_2_finish.x);
    b1 = cut_1_start.y - cut_1_start.x * k1;
    b2 = cut_2_start.y - cut_2_start.x * k2;
    
    if (is_paralel(k1, k2))
        return parallel_case(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish);
    
    intersect_point.x = (b2 - b1) / (k1 - k2);
    intersect_point.y = k1 * intersect_point.x + b1;

    return is_on_segments(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish, intersect_point);
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

double cuts_distance(cord cut_1_start, cord cut_1_finish, cord cut_2_start, cord cut_2_finish)
{
    if (is_intersecting(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish)) return 0;
    
    return min(min(cut_distance(cut_1_start, cut_1_finish, cut_2_start),
               cut_distance(cut_1_start, cut_1_finish, cut_2_finish)),
               min(cut_distance(cut_2_start, cut_2_finish, cut_1_start),
               cut_distance(cut_2_start, cut_2_finish, cut_1_finish)));
               
}

int main()
{
    cord cut_1_start, cut_1_finish, cut_2_start, cut_2_finish;
    cin >> cut_1_start.x >> cut_1_start.y >> cut_1_finish.x >> cut_1_finish.y;
    cin >> cut_2_start.x >> cut_2_start.y >> cut_2_finish.x >> cut_2_finish.y;
    
    cout << fixed << setprecision(6) << cuts_distance(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish);
}
