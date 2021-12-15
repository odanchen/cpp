#include <bits/stdc++.h>

using namespace std;

void generate_arr(int arr[][2], int &length, int limit)
{
    length = 0;
    int dil;
    for (int i = 1; i <= limit; i++)
    {
        for(int j = 2; j <= limit; j++)
        {
            dil = __gcd(i, j);
            if (dil == 1 && (double)((double)i / (double)j) < 1)
            {
                arr[length][0] = i;
                arr[length][1] = j;
                length++;
            }
        }
    }
}

bool compare(int a[], int b[])
{
    return (double)a[0] / (double)a[1] > (double)b[0] / (double)b[1];
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[100000][2], length, limit;
    cin >> limit;
    generate_arr(arr, length, limit);
    quicksort(arr, 0, length - 1);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i][0] << "/" << arr[i][1] << "\n";
    }
    return 0;
}
