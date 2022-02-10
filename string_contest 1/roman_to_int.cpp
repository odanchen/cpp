#include<iostream>

using namespace::std;

void map_fill(int map[])
{
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
}

int convert(string S)
{
    int map[128];
    map_fill(map);
    int cur = map['I'], sum = 0;
    
    for (int i = S.size() - 1; i >= 0; i--)
    {
        if (map[S[i]] >= cur)
        {
            sum += map[S[i]];
            cur = map[S[i]];
        }
        else
            sum -= map[S[i]];
    }
    
    return sum;
}

int main()
{
    string S;
    cin >> S;
    
    cout << convert(S);
}
