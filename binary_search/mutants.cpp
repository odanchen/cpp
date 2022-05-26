#include<iostream>
#include<cmath>

using namespace::std;

int find_right_pos(int arr[], int len, int request)
{
    int left = 0, right = len - 1, mid = (left + right) / 2;
    
    
    while(left < right)
    {
        mid = (left + right) / 2;
        if (arr[right] == request) return right;
        
        if (arr[mid] == request && arr[mid + 1] == request) left = mid + 1;
        else if (arr[mid] == request) return mid;
        if (arr[mid] < request) left = mid + 1;
        if (arr[mid] > request) right = mid - 1;
    }
    
    if (arr[right] == request) return right;
    if (arr[mid] == request) return mid;
    if (arr[left] == request) return left;
    
    return -1;
}

int find_left_pos(int arr[], int len, int request)
{
    int left = 0, right = len - 1, mid = (left + right) / 2;
    
    
    while(left < right)
    {
        mid = (left + right) / 2;
        if (arr[left] == request) return left;
        
        if (arr[mid] == request && arr[mid - 1] == request) right = mid - 1;
        else if (arr[mid] == request) return mid;
        if (arr[mid] < request) left = mid + 1;
        if (arr[mid] > request) right = mid - 1;
    }
    
    if (arr[left] == request) return left;
    if (arr[mid] == request) return mid;
    if (arr[right] == request) return right;
    
    return -1;
}

int count_mutants(int arr[], int len, int request)
{
    int left = find_left_pos(arr, len, request), right = find_right_pos(arr, len, request);
    
    if (left == -1 || right == -1) return 0;
    return right - left  + 1;
}

void read_arr(int arr[], int &len)
{
    cin >> len;
    
    for(int i = 0; i < len; i++)
        cin >> arr[i];
}

int main()
{
    int arr[1000000], len, request_len, request_arr[200000];
    
    read_arr(arr, len);
    read_arr(request_arr, request_len);
    
    for (int i = 0; i < request_len; i++)
    {
        cout << count_mutants(arr, len, request_arr[i]) << '\n';
    }
}
