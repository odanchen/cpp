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

bool is_paralel(double k1, double k2)
{
    return fabs(k1 - k2) < 1e-6;
}

bool is_equal(double num1, double num2)
{
    return fabs(num1 - num2) < 1e-7;
}

cord vertical_case(cord cut_1_start, cord cut_1_finish, cord cut_2_start, cord cut_2_finish)
{
    double k1, k2, b1, b2;
    cord intersect_point;
    
    if (cut_1_start.x == cut_1_finish.x)
    {
        k2 = (cut_2_start.y - cut_2_finish.y) / (cut_2_start.x - cut_2_finish.x);
        b2 = cut_2_start.y - cut_2_start.x * k2;
        if (k2 == 0)
        {
            intersect_point.x = cut_1_start.x; intersect_point.y = cut_2_start.y;
            return intersect_point;
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
            return intersect_point;
        }
        intersect_point.y = k1 * cut_2_start.x + b1; intersect_point.x = cut_2_start.x;
    }
    
    return intersect_point;
}

cord find_orthocentr(cord cut_1_start, cord cut_1_finish, cord cut_2_start, cord cut_2_finish)
{
    cord intersect_point;
    double k1, k2, b1, b2;
    
    if (fabs(cut_1_finish.x - cut_1_start.x) < 1e-7 || fabs(cut_2_finish.x - cut_2_start.x) < 1e-7)
        return vertical_case(cut_1_start, cut_1_finish, cut_2_start, cut_2_finish);
    
    k1 = (cut_1_start.y - cut_1_finish.y) / (cut_1_start.x - cut_1_finish.x);
    k2 = (cut_2_start.y - cut_2_finish.y) / (cut_2_start.x - cut_2_finish.x);
    b1 = cut_1_start.y - cut_1_start.x * k1;
    b2 = cut_2_start.y - cut_2_start.x * k2;
    
    intersect_point.x = (b2 - b1) / (k1 - k2);
    intersect_point.y = k1 * intersect_point.x + b1;

    return intersect_point;
}

int main()
{
    cord A, B, C, A1, B1;
    cord ans;
    
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    A1 = find_intersect_point(C, B, A);
    B1 = find_intersect_point(A, C, B);
    ans = find_orthocentr(A, A1, B, B1);
    
    cout << fixed << setprecision(6) << ans.x << ' ';
    cout << fixed << setprecision(6) << ans.y;
}
