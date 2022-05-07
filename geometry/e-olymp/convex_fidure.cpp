#include<iostream>
#include<iomanip>
#include<cmath>

using namespace::std;

const double Pi = 3.14159265359;
const double eps = 1e-8;

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

int validate_idx(int len, int idx)
{
    int ans = idx;
    if (ans < 0) ans += + len;
    
    return ans % len;
}

bool is_correct(cord dots[], int len, int idx)
{
    int prev_dot, next_dot, cut_dot_1, cut_dot_2;
    
    prev_dot = validate_idx(len, idx - 1); next_dot = validate_idx(len, idx + 1);
    cut_dot_1 = validate_idx(len, idx - 2); cut_dot_2 = validate_idx(len, idx + 2);
    
    if (len == 4)
        return (distance(dots[idx], dots[cut_dot_1]) > distance(dots[prev_dot], dots[cut_dot_1]) - eps) &&
                (distance(dots[idx], dots[cut_dot_1]) > distance(dots[next_dot], dots[cut_dot_1]) - eps);
    
    return (line_distance(dots[cut_dot_1], dots[cut_dot_2], dots[idx]) >
        line_distance(dots[cut_dot_1], dots[cut_dot_2], dots[prev_dot]) - eps) &&
        (line_distance(dots[cut_dot_1], dots[cut_dot_2], dots[idx]) >
         line_distance(dots[cut_dot_1], dots[cut_dot_2], dots[next_dot]) - eps);
}

void read_arr(cord arr[], int &len)
{
    cin >> len;
    
    for (int i = 0; i < len; i++)
        cin >> arr[i].x >> arr[i].y;
}

bool is_convex(cord dots[], int cnt)
{
    if (cnt == 3) return true;
    
    for (int i = 0; i < cnt; i++)
        if (not(is_correct(dots, cnt, i))) return false;
        
    return true;
}

int main()
{
    cord dots[100000];
    int len;
    
    read_arr(dots, len);
    
    if (is_convex(dots, len)) cout << "YES";
    else cout << "NO";
}
