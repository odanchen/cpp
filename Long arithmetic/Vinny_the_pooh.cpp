#include<iostream>

using namespace::std;

const int nmax = 1001;

struct Tlong
{
    char sign = '+';
    int number[nmax] = {0};
    int len = 1;
};

void input_number(Tlong &num)
{
    string S;
    cin >> S;
    if (S[0] == '-')
    {
        num.sign = '-';
        S.erase(0, 1);
    }
    else if (S[0] == '+')
    {
        num.sign = '+';
        S.erase(0, 1);
    }
    else
        num.sign = '+';
    int length = (int)S.size();
    for (int i = 0; i < length - 1 && S[0] == '0'; i++)
        S.erase(0, 1);
    num.len = (int)S.size();
    if (S[0] == '0')
        num.sign = '+';
    int k = 0;
    for(int i = nmax - num.len; i < nmax; i++)
    {
        num.number[i] = S[k] - '0';
        k++;
    }
    
}

int find_remainder(Tlong num, int dil)
{
    int remainder = 0;
    for (int i = nmax - num.len; i < nmax; i += 0)
    {
        if (remainder < dil)
        {
            remainder *= 10;
            remainder += num.number[i];
            i++;
        }
        else
            remainder %= dil;
    }
    return remainder % dil;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Tlong num;
    int dil, remainder;
    input_number(num);
    cin >> dil;
    remainder = find_remainder(num, dil);
    if (remainder == 0)
        cout << dil;
    else
        cout << remainder;
    return 0;
}
