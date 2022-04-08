#include<iostream>
#include<fstream>

using namespace::std;

bool is_polyndromic(string S)
{
    for(int i = 0; i < S.size(); i++)
    {
        S[i] = tolower(S[i]);
    }
        
    for (int i = 0; i < S.size()/2; i++)
    {
        if (S[i] != S[S.size() - i - 1]) return false;
    }
    return true;
}

int main()
{
    ifstream input("palindrom.in");
    ofstream output("palindrom.out");
    string S;
    bool isempety = true, status = false;
    int len;
    
    input >> len;
    while(input >> S)
    {
        isempety = false;
        if (is_polyndromic(S) && S.size() == len)
        {
            output << S << '\n';
            status = true;
        }
    }
    
    input.close();
    
    if (isempety)
        output << "NULL";
    else if (status == false)
        output << -1;
    
    output.close();
    
    return 0;
}
