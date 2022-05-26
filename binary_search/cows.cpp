#include<iostream>
#include<cmath>

using namespace::std;

void read_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cin >> arr[i];
}

bool is_valid_dist(int dist, int arr[], int len, int cows)
{
    int prev = 0;
    cows--;
    
    for (int i = 1; i < len; i++)
    {
        if (arr[i] - arr[prev] >= dist)
        {
            cows--;
            prev = i;
        }
    }
    
    return cows <= 0;
}

int find_max_dist(int arr[], int len, int cows)
{
    int left = 1, right = arr[len - 1], mid;
    
    while (left < right - 1)
    {
        mid = (left + right) / 2;
        
        if (is_valid_dist(mid, arr, len, cows)) left = mid;
        else right = mid - 1;
    }
    
    if (is_valid_dist(right, arr, len, cows)) return right;
    return left;
}

int main()
{
    int arr[10001], cows, len;
    cin >> len >> cows;
    read_arr(arr, len);
    
    cout << find_max_dist(arr, len, cows);
}
