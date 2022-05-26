#include<iostream>
#include<cmath>

using namespace::std;

int find_pos(int arr[], int len, int request)
{
    int left = 0, right = len - 1, mid = (left + right) / 2;
    
    
    while(left < right)
    {
        mid = (left + right) / 2;
        if (arr[right] == request) return right;
        
        if (arr[mid] == request && arr[mid + 1] == request) left = mid + 1;
        else  if (arr[mid] == request) return mid;
        if (arr[mid] < request) left = mid + 1;
        if (arr[mid] > request) right = mid - 1;
    }
    
    if (arr[right] == request) return right;
    if (arr[mid] == request) return mid;
    if (arr[left] == request) return left;
    
    return -1;
}

void read_arr(int arr[], int len)
{
    for(int i = 0; i < len; i++)
        cin >> arr[i];
}

int main()
{
    int arr[100000], len, request_len, request;
    
    cin >> len >> request_len;
    read_arr(arr, len);

    for (int i = 0; i < request_len; i++)
    {
        cin >> request;
        
        cout << find_pos(arr, len, request) + 1 << '\n';
    }
}
