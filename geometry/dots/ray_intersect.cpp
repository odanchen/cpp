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

bool is_on_rays(cord ray_1_start, cord ray_1_dot, cord ray_2_start, cord ray_2_dot, cord intersect_point)
{
    return (((ray_1_start.x < ray_1_dot.x + 1e-6 && intersect_point.x >= ray_1_start.x - 1e-6) ||
        (ray_1_start.x > ray_1_dot.x - 1e-6 && intersect_point.x <= ray_1_start.x + 1e-6)) &&
        ((ray_2_start.x < ray_2_dot.x + 1e-6 && intersect_point.x >= ray_2_start.x - 1e-6) ||
        (ray_2_start.x > ray_2_dot.x - 1e-6 && intersect_point.x <= ray_2_start.x + 1e-6))) &&
        (((ray_1_start.y < ray_1_dot.y + 1e-6 && intersect_point.y >= ray_1_start.y - 1e-6) ||
        (ray_1_start.y > ray_1_dot.y - 1e-6 && intersect_point.y <= ray_1_start.y + 1e-6)) &&
        ((ray_2_start.y < ray_2_dot.y + 1e-6 && intersect_point.y >= ray_2_start.y - 1e-6) ||
         (ray_2_start.y > ray_2_dot.y - 1e-6 && intersect_point.y <= ray_2_start.y + 1e-6)));
}

bool is_paralel(double k1, double k2)
{
    return abs(k1 - k2) < 1e-6;
}

bool parallel_case(cord ray_1_start, cord ray_1_dot, cord ray_2_start, cord ray_2_dot)
{
    double k1 = (ray_1_start.y - ray_1_dot.y) / (ray_1_start.x - ray_1_dot.x);
    double k2 = (ray_2_start.y - ray_2_dot.y) / (ray_2_start.x - ray_2_dot.x);
    double b1 = ray_1_start.y - ray_1_start.x * k1;
    double b2 = ray_2_start.y - ray_2_start.x * k2;
    
    if (b1 != b2) return false;
    
    if ((ray_1_dot.x > ray_1_start.x && ray_2_dot.x > ray_2_start.x) ||
        (ray_1_dot.x < ray_1_start.x && ray_2_dot.x < ray_2_start.x)) return true;
    
    return is_on_rays(ray_1_start, ray_1_dot, ray_2_start, ray_2_dot, ray_1_start);
}

bool vertical_case(cord ray_1_start, cord ray_1_dot, cord ray_2_start, cord ray_2_dot)
{
    if (ray_1_dot.x == ray_1_start.x && ray_2_dot.x == ray_2_start.x)
    {
        if (ray_1_dot.x != ray_2_dot.x) return false;
        
        if ((ray_1_dot.y > ray_1_start.y && ray_2_dot.y > ray_2_start.y) ||
            (ray_1_dot.y < ray_1_start.y && ray_2_dot.y < ray_2_start.y)) return true;
        
        return is_on_rays(ray_1_start, ray_1_dot, ray_2_start, ray_2_dot, ray_1_start);
    }
    
    double k1, k2, b1, b2;
    cord intersect_point;
    
    if (ray_1_start.x == ray_1_dot.x)
    {
        k2 = (ray_2_start.y - ray_2_dot.y) / (ray_2_start.x - ray_2_dot.x);
        b2 = ray_2_start.y - ray_2_start.x * k2;
        if (k2 == 0)
        {
            intersect_point.x = ray_1_start.x; intersect_point.y = ray_2_start.y;
            return is_on_rays(ray_1_start, ray_1_dot, ray_2_start, ray_2_dot, intersect_point);
        }
        intersect_point.y = k2 * ray_1_start.x + b2; intersect_point.x = ray_1_start.x;
    }
    
    else
    {
        k1 = (ray_1_start.y - ray_1_dot.y) / (ray_1_start.x - ray_1_dot.x);
        b1 = ray_1_start.y - ray_1_start.x * k1;
        if (k1 == 0)
        {
            intersect_point.y = ray_1_start.y; intersect_point.x = ray_2_start.x;
            return is_on_rays(ray_1_start, ray_1_dot, ray_2_start, ray_2_dot, intersect_point);
        }
        intersect_point.y = k1 * ray_2_start.x + b1; intersect_point.x = ray_2_start.x;
    }
    
    return is_on_rays(ray_1_start, ray_1_dot, ray_2_start, ray_2_dot, intersect_point);
}

bool is_intersecting(cord ray_1_start, cord ray_1_dot, cord ray_2_start, cord ray_2_dot)
{

    double k1, k2, b1, b2;
    cord intersect_point;
    
    if (abs(ray_1_dot.x - ray_1_start.x) < 1e-7 || abs(ray_2_dot.x - ray_2_start.x) < 1e-6)
        return vertical_case(ray_1_start, ray_1_dot, ray_2_start, ray_2_dot);
    
    k1 = (ray_1_start.y - ray_1_dot.y) / (ray_1_start.x - ray_1_dot.x);
    k2 = (ray_2_start.y - ray_2_dot.y) / (ray_2_start.x - ray_2_dot.x);
    b1 = ray_1_start.y - ray_1_start.x * k1;
    b2 = ray_2_start.y - ray_2_start.x * k2;
    
    if (is_paralel(k1, k2))
        return parallel_case(ray_1_start, ray_1_dot, ray_2_start, ray_2_dot);
    
    intersect_point.x = (b2 - b1) / (k1 - k2);
    intersect_point.y = k1 * intersect_point.x + b1;

    return is_on_rays(ray_1_start, ray_1_dot, ray_2_start, ray_2_dot, intersect_point);
}

int main()
{
    cord ray_1_start, ray_1_dot, ray_2_start, ray_2_dot;
    cin >> ray_1_start.x >> ray_1_start.y >> ray_1_dot.x >> ray_1_dot.y;
    cin >> ray_2_start.x >> ray_2_start.y >> ray_2_dot.x >> ray_2_dot.y;
    
    if (is_intersecting(ray_1_start, ray_1_dot, ray_2_start, ray_2_dot)) cout << "YES";
    else cout << "NO";
}
