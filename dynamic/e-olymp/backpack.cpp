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

void read_arr(int &len, int arr[])
{
    len = 0;
    int idx = 0;
    string S, separators = " ";
    
    getline(cin, S);
    getline(cin, S);
    while(idx != -1)
    {
        string word = find_word(S, idx, separators);
        arr[len] = stoi(word);
        len++;
    }
}

void fill_map(bool map[], int bars[], int len, int capacity)
{
    map[0] = true;
    
    for (int i = 0; i < len; i++)
        for (int j = capacity; j >= bars[i]; j--)
            if (map[j - bars[i]])
                map[j] = true;
}

int main()
{
    int capacity, len;
    int bars[301] = {0};
    bool map[10000] = {false};
    
    cin >> capacity;
    
    read_arr(len, bars);
    
    fill_map(map, bars, len, capacity);
    
    
    int max = 0;
    for (int i = 0; i <= capacity; i++)
        if (map[i]) max = i;
    
    cout << max;
}
