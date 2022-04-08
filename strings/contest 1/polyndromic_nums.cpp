#include<iostream>

using namespace::std;

bool is_numeric(string S)
{
    if (S[0] == '0') return false;
    
    for (int i = 0; i < S.size(); i++)
    {
        if (not(isdigit(S[i]))) return false;
    }
    
    return true;
}

bool is_polyndromic(string S)
{
    for (int i = 0; i < S.size()/2; i++)
    {
        if (S[i] != S[S.size() - i - 1]) return false;
    }
    return true;
}

int main()
{
    string S;
    bool status = false;
    
    while(cin >> S)
    {
        if (is_numeric(S) && is_polyndromic(S))
        {
            cout << S << '\n';
            status = true;
        }
    }
    
    if (status == false)
        cout << "The notepad is clean.";
    
    return 0;
}
