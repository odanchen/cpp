#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

const double eps = 1e-6;

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
    return (intersect_point.x <= max(cut_1_start.x, cut_1_finish.x) + eps) &&
           (intersect_point.x >= min(cut_1_start.x, cut_1_finish.x) - eps) &&
           (intersect_point.x <= max(cut_2_start.x, cut_2_finish.x) + eps) &&
           (intersect_point.x >= min(cut_2_start.x, cut_2_finish.x) - eps) &&
           (intersect_point.y <= max(cut_1_start.y, cut_1_finish.y) + eps) &&
           (intersect_point.y >= min(cut_1_start.y, cut_1_finish.y) - eps) &&
           (intersect_point.y <= max(cut_2_start.y, cut_2_finish.y) + eps) &&
           (intersect_point.y >= min(cut_2_start.y, cut_2_finish.y) - eps);
}

bool is_paralel(double k1, double k2)
{
    return fabs(k1 - k2) < eps;
}

bool is_equal(double num1, double num2)
{
    return fabs(num1 - num2) < eps;
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
    
    if (is_equal(cut_1_start.x, cut_1_finish.x))
    {
        k2 = (cut_2_start.y - cut_2_finish.y) / (cut_2_start.x - cut_2_finish.x);
        b2 = cut_2_start.y - cut_2_start.x * k2;
        if (is_equal(k2, 0))
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
        if (is_equal(k1, 0))
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
    
    if (is_equal(cut_1_finish.x, cut_1_start.x) || is_equal(cut_2_finish.x, cut_2_start.x))
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

bool inparalel(cord cut_1_start, cord cut_1_finish, cord cut_2_start, cord cut_2_finish)
{
    if (is_equal(cut_1_start.x, cut_1_finish.x) && is_equal(cut_2_start.x, cut_2_finish.x)) return false;
    
    if (is_equal(cut_1_start.x, cut_1_finish.x) || is_equal(cut_2_start.x, cut_2_finish.x)) return true;
    
    double k1, k2;
    k1 = (cut_1_start.y - cut_1_finish.y) / (cut_1_start.x - cut_1_finish.x);
    k2 = (cut_2_start.y - cut_2_finish.y) / (cut_2_start.x - cut_2_finish.x);
    
    return not(is_equal(k1, k2));
}

cord find_intersect_point(cord cut_1_start, cord cut_1_finish, cord cut_2_start, cord cut_2_finish)
{
    cord intersect_point;
    
    if (is_equal(cut_1_start.x, cut_1_finish.x))
    {
        intersect_point.x = cut_1_start.x;
        double k2, b2;
        k2 = (cut_2_start.y - cut_2_finish.y) / (cut_2_start.x - cut_2_finish.x);
        b2 = cut_2_start.y - cut_2_start.x * k2;
        intersect_point.y = k2 * intersect_point.x + b2;
    }
    else if (is_equal(cut_2_start.x, cut_2_finish.x))
    {
        intersect_point.x = cut_2_start.x;
        double k1, b1;
        k1 = (cut_1_start.y - cut_1_finish.y) / (cut_1_start.x - cut_1_finish.x);
        b1 = cut_1_start.y - cut_1_start.x * k1;
        intersect_point.y = k1 * intersect_point.x + b1;
    }
    else
    {
        double k1, k2, b1, b2;
        k1 = (cut_1_start.y - cut_1_finish.y) / (cut_1_start.x - cut_1_finish.x);
        k2 = (cut_2_start.y - cut_2_finish.y) / (cut_2_start.x - cut_2_finish.x);
        b1 = cut_1_start.y - cut_1_start.x * k1;
        b2 = cut_2_start.y - cut_2_start.x * k2;
        
        intersect_point.x = (b2 - b1) / (k1 - k2);
        intersect_point.y = k1 * intersect_point.x + b1;
    }
    
    return intersect_point;
}

bool in_cut(cord A, cord B, cord intersect_point)
{
    return (intersect_point.x >= min(A.x, B.x) - eps) &&
           (intersect_point.x <= max(A.x, B.x) + eps) &&
           (intersect_point.y >= min(A.y, B.y) - eps) &&
           (intersect_point.y <= max(A.y, B.y) + eps);
}

bool comp(cord A, cord B)
{
    if (not(is_equal(A.x, B.x)))
        return A.x > B.x;
    return A.y > B.y;
}

int main()
{
    cord cut_1_start, cut_1_finish, cut_2_start, cut_2_finish;
    cin >> cut_1_start.x >> cut_1_start.y >> cut_1_finish.x >> cut_1_finish.y;
    cin >> cut_2_start.x >> cut_2_start.y >> cut_2_finish.x >> cut_2_finish.y;
    
    if (not(is_intersecting(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish))) cout << "Empty";
    else
    {
        if (inparalel(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish))
        {
            cord intersect_point = find_intersect_point(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish);
            cout << fixed << setprecision(10) << intersect_point.x << ' ' << intersect_point.y;
        }
        else
        {
            cord intersect_start, intersect_finish;
            
            if ((in_cut(cut_2_start, cut_2_finish, cut_1_start)) &&
                (in_cut(cut_2_start, cut_2_finish, cut_1_finish)))
            {
                intersect_start = cut_1_start;
                intersect_finish = cut_1_finish;
            }
            else if ((in_cut(cut_1_start, cut_1_finish, cut_2_start)) &&
                (in_cut(cut_1_start, cut_1_finish, cut_2_finish)))
            {
                intersect_start = cut_2_start;
                intersect_finish = cut_2_finish;
            }
            else
            {
                if (in_cut(cut_2_start, cut_2_finish, cut_1_start)) intersect_start = cut_1_start;
                else intersect_start = cut_1_finish;
            
                if (in_cut(cut_1_start, cut_1_finish, cut_2_start)) intersect_finish = cut_2_start;
                else intersect_finish = cut_2_finish;
            }
            
            if (is_equal(intersect_start.x, intersect_finish.x) &&
                is_equal(intersect_start.y, intersect_finish.y))
                cout << fixed << setprecision(10) << intersect_start.x << ' ' << intersect_start.y;
            else
            {
                if (comp(intersect_start, intersect_finish)) swap(intersect_start, intersect_finish);
                cout << fixed << setprecision(10) << intersect_start.x << ' ';
                cout << fixed << setprecision(10) << intersect_start.y << '\n';
                cout << fixed << setprecision(10) << intersect_finish.x << ' ';
                cout << fixed << setprecision(10) << intersect_finish.y;
            }
        }
    }
}
