#include<bits/stdc++.h>

using namespace::std;

void read_arr(int &len, int arr[])
{
    cin >> len;
    
    for (int i = 0; i < len; i++)
        cin >> arr[i];
}

int find_len(int nails[], int cnt)
{
    int lengths[100][2];
    
    lengths[0][0] = 20000;
    lengths[0][1] = 0;
    
    for (int i = 1; i < cnt; i++)
    {
        lengths[i][0] = min(lengths[i - 1][0], lengths[i - 1][1]) + (nails[i] - nails[i - 1]);
        lengths[i][1] = lengths[i - 1][0];
    }
    
    return lengths[cnt - 1][0];
}

int main()
{
    int nails[100], cnt;
    read_arr(cnt, nails);
    sort(nails, nails + cnt);
    
    cout << find_len(nails, cnt);
}
