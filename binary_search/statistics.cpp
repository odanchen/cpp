#include<bits/stdc++.h>

using namespace::std;

struct city
{
    int num;
    int name;
};

bool comp(city a, city b)
{
    if (a.num != b.num) return a.num < b.num;
    return a.name < b.name;
}

void read_arr(city arr[], int &len)
{
    cin >> len;
    
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i].num;
        arr[i].name = i + 1;
    }
}

bool is_city(int l_border, int r_border, city arr[], int request, int len)
{
    int mid, left = 0, right = len - 1;
    city left_comp;
    left_comp.num = request; left_comp.name = l_border;
    
    while(left < right)
    {
        mid = (left + right) / 2;
        
        if (comp(arr[mid], left_comp)) left = mid + 1;
        else right = mid;
    }
    
    return (arr[left].num == request && arr[left].name >= l_border && arr[left].name <= r_border);
}

int main()
{
    int len, requests, request, l_border, r_border;
    city cities[70000];
    
    read_arr(cities, len);
    sort(cities, cities + len, comp);
    
    cin >> requests;
    
    for (int i = 0; i < requests; i++)
    {
        cin >> l_border >> r_border >> request;
        
        if (is_city(l_border, r_border, cities, request, len)) cout << '1';
        else cout << '0';
    }
}
