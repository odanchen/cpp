#include<iostream>
#include<cmath>

using namespace::std;

string find_word(string S, int &start_idx, string separators)
{
    int start = S.find_first_not_of(separators, start_idx);
    int finish = S.find_first_of(separators, start);
    
    if (start == -1) start_idx = -1;
    else start_idx = finish;
    
    if (start == -1 || start > S.size()) return "";
    if (finish == -1 || finish > S.size()) return S.substr(start);
    
    return S.substr(start, finish - start);
}

bool is_numeric(string S)
{
    for (int i = 0; i < S.size(); i++)
        if (not(isdigit(S[i]))) return false;
    return true;
}

int str_to_int(string S)
{
    int sum = 0, grade = 1;
    for (int i = 0; i < S.size(); i++)
    {
        sum += (S[S.size() - i - 1] - '0') * grade;
        grade *= 10;
    }
    return sum;
}

bool is_armstrong(string S)
{
    if (not(is_numeric(S))) return false;
    
    int len = (int)S.size(), num = str_to_int(S), sum = 0;
    int grade = 10;
    for(int i = 0; i < len; i++)
    {
        int digit = (num % grade) / (grade / 10);
        grade *= 10;
        sum += pow(digit, len);
    }
    return sum == num;
}

int main()
{
    freopen("armstrong.in", "r", stdin);
    freopen("armstrong.out", "w", stdout);
    
    string separators = " .,;:!?\"[]";
    string S;
    bool no_armstrong = true;
    
    while(getline(cin, S))
    {
        int start_idx = 0;
        
        while(start_idx != -1)
        {
            string sub;
            sub = find_word(S, start_idx, separators);
            if (is_armstrong(sub))
            {
                cout << sub << '\n';
                no_armstrong = false;
            }
        }
    }
    
    if (no_armstrong) cout << -1;
}
