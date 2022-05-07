#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

double count_bisector(double main, double b, double c)
{
    double p = (main + b + c) / 2;
    return 2 * sqrt(b * c * p * (p - main)) / (b + c);
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(3) << count_bisector(a, b, c) << '\n';
    cout << fixed << setprecision(3) << count_bisector(b, c, a) << '\n';
    cout << fixed << setprecision(3) << count_bisector(c, a, b) << '\n';
}
