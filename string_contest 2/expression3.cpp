#include<iostream>
#include<iomanip>
#include<cmath>

using namespace::std;

string find_word(string S, int &start_idx, string separators)
{
    int start = S.find_first_not_of(separators, start_idx);
    int finish = S.find_first_of(separators, start);
    
    if (start == -1) start_idx = -1;
    else start_idx = finish;
    
    if (start != 0) start -= 1;
    
    if (start == -1 || start > S.size()) return "";
    if (finish == -1 || finish > S.size()) return S.substr(start);
    
    return S.substr(start, finish - start);
}

void swap_sign(char &sign)
{
    if (sign == '+') sign = '-';
    else if (sign == '-') sign  = '+';
}

void open_gaps(string &S)
{
    int start_idx = 0;
    char sign;
    string gaps = "()";
    string operations = "+-";
    
    while(start_idx != -1)
    {
        int open = S.find_first_of(gaps, start_idx);
        int close = S.find_first_of(gaps, open + 1);
        if (open == 0) sign = '+';
        else sign = S[open - 1];
        
        if (open == -1) return;
        close--;
        
        S.erase(open, 1);
        
        if (open != 0)
        {
            if (not(isdigit(S[open])) && not(isdigit(S[open - 1])))
            {
                if (S[open] == S[open - 1])
                {
                    S.erase(open - 1, 1);
                    S[open - 1] = '+';
                    close--;
                }
                else if (S[open] != S[open - 1])
                {
                    S.erase(open - 1, 1);
                    S[open - 1] = '-';
                    close--;
                }
            }
        }
        
        for (int i = open; i < close; i++)
        {
            if (not(isdigit(S[i])) && sign == '-') swap_sign(S[i]);
        }
        
        if (close >= S.size() || close < 0)
            S.erase(S.size() - 1, 1);
        else
            S.erase(close, 1);
        
        start_idx = close;
    }
}

int main()
{
    freopen("expression_3.in", "r", stdin);
    freopen("expression_3.out", "w", stdout);
    
    string operations = "+-";
    string S;
    
    while(getline(cin, S))
    {
        if (S[S.size() - 1] == '\r') S.erase(S.size() - 1, 1);
        if (S.empty()) cout << "NULL" << '\n';
        else
        {
            open_gaps(S);
            int start_idx = 0;
            long long sum = 0;
            
            while(start_idx != -1)
            {
                int add = stoi(find_word(S, start_idx, operations));
                sum += add;
            }
            
            cout << sum << '\n';
        }
    }
}
