#include <bits/stdc++.h>

using namespace std;

void read_arr(int arr[][2], int &length)
{
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i][0];
        arr[i][1] = i;
    }
}

bool compare(int a[], int b[])
{
    if (a[0] == b[0])
        return b[1] > a[1];
    return a[0] > b[0];
}

void quicksort(int arr[][2], int left, int right)
{
    int i = left, j = right, etalon[2];
    for (int k = 0; k <= 1; k++)
        etalon[k] = arr[(i + j) / 2][k];
    while(i < j)
    {
            while (compare(etalon, arr[i])) i++;
            while (compare(arr[j], etalon)) j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if(left < j) quicksort(arr, left, j);
    if(i < right) quicksort(arr, i, right);
}

bool is_unique(int arr[][2], int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i][0] == arr[i + 1][0]) return false;
    return true;
}

int main()
{
    int arr[100000][2], length, ans_arr[100000], ans_length;
    read_arr(arr, length);
    quicksort(arr, 0, length - 1);
    if (is_unique(arr, length))
        cout << "I will have to harm my health.";
    else
    {
        int i = length - 1;
        while(arr[i][0] != arr[i - 1][0])
            i--;
        cout << arr[i][1] + 1 << " " << arr[i - 1][1] + 1;
    }
    return 0;
}
