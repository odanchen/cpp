#include <bits/stdc++.h>
using namespace std;

void read_arr(int arr[], int &length)
{
    length = 0;
    while (cin.peek() != '\n')
        cin >> arr[length++];
}

bool is_progression(int arr[], int length)
{
    int step = arr[1] - arr[0];
    for (int i = 0; i < length - 1; i++)
        if (arr[i] != arr[i + 1] - step) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[100000], length;
    read_arr(arr, length);
    sort(arr, arr + length);
    if (is_progression(arr, length))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
