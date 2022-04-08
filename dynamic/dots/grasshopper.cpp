#include<iostream>

using namespace::std;

int count_ways(int len, int jump)
{
    int steps[40] = {0};
    steps[1] = 1;
    steps[2] = 1;
    
    int i;
    
    for(i = 3; i <= jump; i++)
        steps[i] = 2 * steps[i - 1];

    for(; i <= len; i++)
        steps[i] = 2 * steps[i - 1] - steps[i - jump - 1];
    
    return steps[len];
}

int main()
{
    int len, jump;
    cin >> len >> jump;
    cout << count_ways(len, jump);
}
