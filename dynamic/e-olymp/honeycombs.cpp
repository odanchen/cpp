#include<iostream>

using namespace::std;

int count_ways(int num)
{
    int arr[100];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    
    for (int i = 3; i < num * 2 - 1; i++)
    {
        if (i & 1) arr[i] = arr[i - 2] + arr[i - 3];
        else arr[i] = arr[i - 1];
    }
    
    return arr[(num - 1) * 2];
}

int main()
{
    int num;
    cin >> num;
    
    cout << count_ways(num);
}
