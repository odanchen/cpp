#include<iostream>

using namespace::std;

bool is_valid(string S)
{
    int sum = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if ((S[i] - '0') % 3 != 0)
            sum += (S[i] - '0');
    }
    return (sum % 3 == 0);
}

int main()
{
    string S;
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; i++)
    {
        cin >> S;
        if (is_valid(S))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    
    return 0;
}
