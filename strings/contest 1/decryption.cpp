#include<iostream>

using namespace::std;

void read_codes(string codes[])
{
    for (int i = 0; i < 10; i++)
    {
        getline(cin, codes[i]);
    }
}

void print_arr(int digits[])
{
    for (int i = 0; i < 8; i++)
        cout << digits[i];
}

void decrypt(int digits[], string codes[], string S)
{
    string substring = "0000000000";
    
    for (int i = 0; i < 8; i++)
    {
        bool pass = false;
        
        for (int j = 0; j < 10; j++)
            substring[j] = S[i * 10 + j];
        
        for (int j = 0; j < 10; j++)
        {
            if (substring == codes[j])
            {
                digits[i] = j;
                pass = true;
            }
        }
        
        if (not(pass))
        {
            digits[0] = -1;
            return;
        }
    }
}

int main()
{
    string S, codes[10];
    int digits[8] = {0};
    getline(cin, S);
    read_codes(codes);
    
    decrypt(digits, codes, S);
    if (digits[0] == -1)
        cout << -1;
    else
        print_arr(digits);
    
    return 0;
}
