#include<iostream>

using namespace::std;

void read_arr(int &len, int arr[])
{
    cin >> len;
    
    for (int i = 1; i <= len; i++)
        cin >> arr[i];
}

int count_sum(int cnt, int step, int stairs[])
{
    int max;
    
    stairs[0] = 0;
    stairs[cnt + 1] = 0;
    
    int j = 0;
    
    for(int i = 1; i <= cnt + 1; i++)
    {
        max = stairs[j];
        
        for(j = i - step; j < i; j++)
        {
            if (j < 0) j = 0;
            if (max < stairs[j]) max = stairs[j];
        }
        
    stairs[i] = max + stairs[i];
    }
    
    return stairs[cnt + 1];
}

int main()
{
    int cnt, step, stairs[1010];
    read_arr(cnt, stairs);
    cin >> step;
    
    cout << count_sum(cnt, step, stairs);
}
