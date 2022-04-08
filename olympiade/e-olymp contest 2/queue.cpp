#include<iostream>

using namespace::std;

int main()
{
    int num, group, interval, time, sum = 0;
    cin >> num >> group >> interval >> time;
    sum = group * ((time / interval) + 1);
    if (sum >= num)
        cout << num;
    else
        cout << sum % num;
}
