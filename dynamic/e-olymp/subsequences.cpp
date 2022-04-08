#include<iostream>

using namespace::std;

void read_arr(long long arr[], int &len)
{
    cin >> len;
    
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
}

void fill_1(long long arr[], int len)
{
    for(int i = 0; i < len; i++)
        arr[i] = 1;
}

long long count_sub_len(long long arr[], int len)
{
    long long help[1000];
    fill_1(help, len);
    
    for (int i = 0; i < len; i++)
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i]) help[i] = max(help[i], 1 + help[j]);
    
    long long res = 0;
    for (int i = 0; i < len; i++)
        res = max(res, help[i]);
    
    return res;
}

int main()
{
    long long arr[1000];
    int len;
    
    read_arr(arr, len);
    
    cout << count_sub_len(arr, len);
}
