#include<iostream>

using namespace::std;

int count_ways(int len, int jump)
{
    int steps[len];
    steps[0] = 1;
    steps[1] = 1;
    
    for (int i = 2; i < jump; i++)
        steps[i] = steps[i - 1] * 2;
    
    for (int i = jump; i < len; i++)
        steps[i] = steps[i - 1] * 2 - steps[i - jump - 1];
    
    return steps[max(len, jump) - 1];
}

int main()
{
    int len, jump;
    cin >> len >> jump;
    cout << count_ways(len, jump);
}
