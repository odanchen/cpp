#include <bits/stdc++.h>

using namespace std;

void read_arr(int arr[], int &length)
{
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> arr[i];
}

long long find_imp_num(int arr[], int length)
{
    long long res = 1;
    for (int i = 0; i < length && arr[i] <= res; i++)
        res = res + arr[i];
    return res;
}

int main()
{
    int arr[100000], length;
    read_arr(arr, length);
    sort(arr, arr + length);
    cout << find_imp_num(arr, length);
}
