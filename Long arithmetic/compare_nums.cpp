#include<iostream>

using namespace::std;

const int nmax = 1001;

struct Tlong
{
    char sign;
    int number[nmax];
    int len;
};

void clear_num(Tlong num)
{
    for (int i = 0; i < nmax; i++)
        num.number[i] = 0;
}

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
    for (int i = 0; i < length && S[0] == '0'; i++)
        S.erase(0, 1);
    num.len = (int)S.size();
    if (S[0] == '0')
        num.sign = '+';
    clear_num(num);
    int k = 0;
    for(int i = nmax - num.len; i < nmax; i++)
    {
        num.number[i] = S[k] - '0';
        k++;
    }
    
}

int compare_abs(Tlong &a, Tlong &b)
{
    if (a.len > b.len) return 1;
    if (a.len < b.len) return -1;
    for (int i = nmax - a.len; i < nmax; i++)
    {
        if (a.number[i] > b.number[i]) return 1;
        if (a.number[i] < b.number[i]) return -1;
    }
    return 0;
}

int compare(Tlong &a, Tlong &b)
{
    if (a.sign == '+' && b.sign == '-') return 1;
    if (a.sign == '-' && b.sign == '+') return -1;
    if (a.sign == '+' && b.sign == '+') return compare_abs(a, b);
    if (a.sign == '-' && b.sign == '-') return -compare_abs(a, b);
    return 0;
}

void print_num(Tlong num)
{
    if (num.sign == '-') cout << '-';
    for (int i = nmax - num.len; i < nmax; i++)
        cout << num.number[i];
}

int main()
{
    Tlong num1, num2;
    input_number(num1);
    input_number(num2);
    print_num(num1);
    if (compare(num1, num2) == 1) cout << '>';
    if (compare(num1, num2) == 0) cout << '=';
    if (compare(num1, num2) == -1) cout << '<';
    print_num(num2);
    return 0;
}
