#include<iostream>
#include<cmath>

using namespace::std;

bool is_in_collection(int arr[], int len, int request)
{
    int left = 0, right = len - 1, mid = (left + right) / 2;
    
    
    while(left < right)
    {
        mid = (left + right) / 2;
        
        if (arr[mid] == request) return true;
        if (arr[mid] < request) left = mid + 1;
        if (arr[mid] > request) right = mid - 1;
    }
    
    if (arr[right] == request) return true;
    if (arr[mid] == request) return true;
    if (arr[left] == request) return true;
    
    return false;
}

void read_arr(int arr[], int &len)
{
    cin >> len;
    
    for(int i = 0; i < len; i++)
        cin >> arr[i];
}

int main()
{
    int arr[100000], len, request_len, request_arr[100000];
    
    read_arr(arr, len);
    read_arr(request_arr, request_len);
    
    for (int i = 0; i < request_len; i++)
    {
        if (is_in_collection(arr, len, request_arr[i])) cout << "YES\n";
        else cout << "NO\n";
    }
}
