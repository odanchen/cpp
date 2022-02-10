#include<iostream>

using namespace std;

void clear_arr(int arr[])
{
    for (int i = 0; i < 256; i++)
        arr[i] = 0;
}

string longestSubstringWithoutDuplication(string str) {
    int arr[256] = {0}, start = 0, finish = 0;
    int max_len = 0, idx1 = 0, idx2 = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int len = 0;
        idx1 = i;
        while(arr[str[i]] == 0 && i < str.size())
        {
            arr[str[i]]++;
            len++;
            i++;
        }
        arr[str[i]]++;
        idx2 = i;
        if (len > max_len)
        {
            max_len = len;
            start = idx1;
            finish = idx2;
        }
        
        if(arr[str[i]] == 2)
        {
            char find = str[i];
            i--;
            while(str[i] != find)
                i--;
        }
        
        clear_arr(arr);
    }
    
    string res;
    for (int i = start; i < finish; i++)
        res += str[i];
  return res;
}

int main()
{
    string S;
    cin >> S;
    cout << longestSubstringWithoutDuplication(S);
}
