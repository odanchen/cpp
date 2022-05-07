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

double find_angle(cord main_dot, cord dot1, cord dot2)
{
    double main, b, c;
    main = distance(dot1, dot2);
    b = distance(main_dot, dot1);
    c = distance(main_dot, dot2);
    
    return acos((sqr(b) + sqr(c) - sqr(main)) / (2 * b * c)) * 180 / 3.14159265359;
}

void read_arr(cord arr[], int &len)
{
    len = 0;
    string S;
    while(cin >> S)
    {
        arr[len].x = stod(S);
        cin >> S;
        arr[len].y = stod(S);
        len++;
    }
}

int main()
{
    int cnt = 0, len;
    cord dots[100];
    
    read_arr(dots, len);
    for (int i = 1; i < len - 1; i++)
        if (fabs(find_angle(dots[i], dots[i - 1], dots[i + 1]) - 90) < 1e-8) cnt++;
    
    if (fabs(find_angle(dots[0], dots[1], dots[len - 1]) - 90) < 1e-8) cnt++;
    if (fabs(find_angle(dots[len - 1], dots[len - 2], dots[0]) - 90) < 1e-8) cnt++;
    
    cout << cnt;
}
