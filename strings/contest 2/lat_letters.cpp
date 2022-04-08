#include<iostream>

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

int count_unique(string S)
{
    char arr[256] = {0};
    int cnt = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (arr[toupper(S[i])] == 0 && isalpha(S[i])) cnt++;
        arr[toupper(S[i])]++;
    }
    return cnt;
}

void print_arr(string arr[], int max_idx)
{
    for (int i = 0; i <= max_idx; i++)
        cout << arr[i] << ' ';
}

int main()
{
    freopen("maxsymbol.in", "r", stdin);
    freopen("maxsymbol.out", "w", stdout);
    
    string separators = ".,;:!?\"[] \n\t\v\f\r";
    string S;
    bool no_words = true, empty = true;
    int maximum = 0, idx = 0;
    string arr[1000];
    
    while(getline(cin, S))
    {
        int start_idx = 0;
        empty = false;
        
        while(start_idx != -1)
        {
            string word = find_word(S, start_idx, separators);
            
            if (count_unique(word) > maximum)
            {
                idx = 0;
                maximum = count_unique(word);
                arr[idx] = word;
                no_words = false;
            }
            else if(count_unique(word) == maximum && count_unique(word) != 0)
            {
                idx++;
                arr[idx] = word;
            }
            
        }
    }
    
    if (empty) cout << "NULL";
    else if (no_words) cout << -1;
    else print_arr(arr, idx);
}
