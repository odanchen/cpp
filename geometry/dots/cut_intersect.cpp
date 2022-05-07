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

int main()
{
    cord cut_1_start, cut_1_finish, cut_2_start, cut_2_finish;
    cin >> cut_1_start.x >> cut_1_start.y >> cut_1_finish.x >> cut_1_finish.y;
    cin >> cut_2_start.x >> cut_2_start.y >> cut_2_finish.x >> cut_2_finish.y;
    
    if (is_intersecting(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish)) cout << "YES";
    else cout << "NO";
}
