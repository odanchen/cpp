#include<iostream>

using namespace::std;

bool is_valid(string S)
{
    int idx = 0;
    char opened[S.size()];
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '~')
        {
            opened[idx] = '(';
            idx++;
        }
        else if (S[i] == '#')
        {
            opened[idx] = '[';
            idx++;
        }
        else if (S[i] == '%')
        {
            opened[idx] = '{';
            idx++;
        }
        else if (idx == 0) return false;
        else if (S[i] == '@' && opened[idx - 1] == '(') idx--;
        else if (S[i] == '$' && opened[idx - 1] == '[') idx--;
        else if (S[i] == '&' && opened[idx - 1] == '{') idx--;
        else return false;
    }
    if (idx != 0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string S;
    while(cin >> S)
    {
        if (is_valid(S)) cout << "OK";
        else cout << "WRONG";
        cout << '\n';
    }

    return 0;
}
