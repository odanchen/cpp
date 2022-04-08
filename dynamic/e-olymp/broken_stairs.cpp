#include<iostream>

using namespace::std;

void read_arr(int &len, long long arr[])
{
    cin >> len;
    int pos;
    
    for (int i = 0; i < len; i++)
    {
        cin >> pos;
        arr[pos] = -1;
    }
}

long long count_ways(int num, int break_cnt, long long stairs[])
{
    stairs[0] = 1;
    if (stairs[1] != -1) stairs[1] = 1;
    else stairs[1] = 0;
    
    if (stairs[2] != -1) stairs[2] = stairs[1] + stairs[0];
    else stairs[2] = 0;
    
    for (int i = 3; i <= num; i++)
    {
        if(stairs[i] == -1) stairs[i] = 0;
        else
            stairs[i] = stairs[i - 1] + stairs[i - 2] + stairs[i - 3];
    }
    
    if (stairs[num] == 0) return -1;
    return stairs[num];
}

int main()
{
    int num, break_cnt;
    long long stairs[100] = {0};
    cin >> num;
    read_arr(break_cnt, stairs);
    
    cout << count_ways(num, break_cnt, stairs);
}
