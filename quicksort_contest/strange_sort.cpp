#include <bits/stdc++.h>

using namespace std;

void read_arr(int arr[], int &length)
{
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> arr[i];
}

void print_arr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
}

bool compare(int a, int b)
{
    if (a % 10 == b % 10)
        return a > b;
    else
        return (a % 10 > b % 10);
}

int main()
{
    int arr[1000], length;
    read_arr(arr, length);
    sort(arr, arr + length, compare);
    print_arr(arr, length);
}
