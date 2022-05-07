#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

int main()
{
    double S, R, r;
    cin >> S >> R;
    r = sqrt(fabs(S / 3.141592 - R * R));
    cout << fixed << setprecision(2) << r;
}
