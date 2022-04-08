#include <bits/stdc++.h>

using namespace::std;

bool comp(string &a, string &b)
{
    return a.size() < b.size();
}

bool is_substr(string arr[], int cnt, string subs)
{
    for (int i = 0; i < cnt; i++)
    {
        if (arr[i].find(subs) == -1) return false;
    }
    return true;
}

int count_len(string strings[], int cnt)
{
    int size = 0;
    string subs;
    bool status = true;
    while(status && size <= strings[0].size())
    {
        status = false;
        for (int i = 0; i < strings[0].size() - size && status == false; i++)
        {
            subs = strings[0].substr(i, size + 1);
            if (is_substr(strings, cnt, subs))
            {
                size++;
                i = 0;
                status = true;
            }
        }
    }
    
    return size;
}

int main()
{
    int cnt;
    cin >> cnt;
    string strings[cnt];
    for (int i = 0; i < cnt; i++)
        cin >> strings[i];
    
    sort(strings, strings + cnt, comp);
    
    cout << count_len(strings, cnt);
}
