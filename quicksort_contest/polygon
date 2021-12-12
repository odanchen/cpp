//#include<bits/stdc++.h>
#include<iostream>

using namespace::std;

void read_arr(unsigned int arr[], int &length)
{
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> arr[i];
}

int count_sides(unsigned int arr[], int length)
{
    long long part_sum = 0;
    for (int i = 0; i < length - 1; i++)
        part_sum += arr[i];
    int i = length - 1;
    while(arr[i] >= part_sum && i > 0)
    {
        part_sum -= arr[i - 1];
        i--;
        length--;
    }
    if (length < 3) length = 0;
    return length;
}

int _main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned int arr[1000000];
    int length, sides;
    read_arr(arr, length);
    sort(arr, arr + length);
    sides = count_sides(arr, length);
    if (sides > 2)
        cout << sides;
    else
        cout << 0;
    return 0;
}
