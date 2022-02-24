#include<iostream>

using namespace::std;

string find_num(string S, int &start_idx, string separators)
{
    int start = S.find_first_not_of(separators, start_idx);
    int finish = S.find_first_of(separators, start);
    
    if (start == -1) start_idx = -1;
    else start_idx = finish;
    
    if (start == -1 || start > S.size()) return "";
    if (finish == -1 || finish > S.size()) return S.substr(start);
    
    return S.substr(start, finish - start);
}

int min_system(string S)
{
    int res = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (isalpha(S[i])) res = max(res, S[i] - 'A' + 11);
        if (isdigit(S[i])) res = max(res, S[i] - '0');
    }
}

int main()
{
    
}
