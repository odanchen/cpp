#include<iostream>
#include<iomanip>

using namespace::std;

const double eps = 1e-9;

double value(double a, double b, double c, double d, double x)
{
    return (a * x * x * x) + (b * x * x) + (c * x) + d;
}

double solve(int a, int b, int c, int d)
{
    double left, right = 1, mid = 0;
    
    while(value(a, b, c, d, right) * value(a, b, c, d, -right) >= 0) right *= 2;
    left = -right;
    
    while(right - left > eps)
    {
        mid = (left + right) / 2;
        
        if (value(a, b, c, d, right) == 0) return right;
        if (value(a, b, c, d, mid) == 0) return mid;
        if (value(a, b, c, d, left) == 0) return left;
        
        if ((value(a, b, c, d, right) * value(a, b, c, d, mid)) > 0) right = mid;
        else left = mid;
    }
    
    return left;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    cout << fixed << setprecision(6) << solve(a, b, c, d);
}
