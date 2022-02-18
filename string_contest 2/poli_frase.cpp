#include<iostream>

using namespace::std;

string find_phrase(string S, int &start_idx, string separators)
{
    int start = S.find_first_not_of(separators, start_idx);
    int finish = S.find_first_of(separators, start);
    
    if (start == -1) start_idx = -1;
    else start_idx = finish;
    
    if (start == -1 || start > S.size()) return "";
    if (finish == -1 || finish > S.size()) return S.substr(start);
    
    return S.substr(start, finish - start);
}

bool is_polindromic(string &S)
{
    int p1 = 0, p2 = S.size() - 1;
    if (S.empty()) return false;
    bool found = false;
        
    while(p1 <= p2)
    {
        
        while(not(isalpha(S[p1])) && p1 <= p2)
            p1++;
        
        while(not(isalpha(S[p2])) && p2 >= p1)
            p2--;
        
        if(toupper(S[p1]) == toupper(S[p2]))
        {
            p1++;
            p2--;
            found = true;
        }
        else return false;
    }
    
    return found;
}

int main()
{
    freopen("palindrom.in", "r", stdin);
    freopen("palindrom.out", "w", stdout);
    
    string S;
    string separators = "!.?";
    string phrase;
    bool found = false;
    
    int pos = 0;
    while(getline(cin, S))
    {
        while(pos < S.size() - 1)
        {
            phrase = find_phrase(S, pos, separators);
            if(is_polindromic(phrase))
            {
                cout << phrase << '\n';
                found = true;
            }
        }
        pos = 0;
    }
    if(not(found)) cout<< -1;
    return 0;
}
