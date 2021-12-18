#include<iostream>

using namespace::std;

const int nmax = 5001;

struct Tlong
{
    char sign = '+';
    int number[nmax] = {0};
    int len = 1;
};

bool iszero(Tlong a)
{
    return a.len == 1 && a.number[nmax - 1] == 0;
}


void clear_num(Tlong num)
{
    for (int i = 0; i < nmax; i++)
        num.number[i] = 0;
}

int get_len(Tlong a)
{
    int i=0;
    while(a.number[i] == 0 && i < nmax) i++;
    if (i == nmax) return 1;
    return nmax - i;
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
    for (int i = 0; i < length - 1 && S[0] == '0'; i++)
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

int compare_abs(Tlong a, Tlong b)
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

int compare(Tlong a, Tlong b)
{
    if (a.sign == '+' && b.sign == '-') return 1;
    if (a.sign == '-' && b.sign == '+') return -1;
    if (a.sign == '+' && b.sign == '+') return compare_abs(a, b);
    if (a.sign == '-' && b.sign == '-') return -compare_abs(a, b);
    return 0;
}

Tlong add_abs(Tlong a, Tlong b)
{
    Tlong res;
    int sum, rest = 0;
    int len = max(a.len,b.len);
    for (int i = nmax - 1; i >= nmax - len - 1; i--)
    {
        sum = a.number[i] + b.number[i] + rest;
        res.number[i] = sum % 10;
        rest = sum / 10;
    }
    res.len = get_len(res);
    return res;
}

Tlong sub_abs(Tlong a, Tlong b)
{
    Tlong res;
    int borrow = 0;
    int len = max(a.len, b.len);
    for (int i = nmax - 1; i >= nmax - len; i--)
    {
        res.number[i] = a.number[i] - b.number[i] - borrow;
        if (res.number[i] < 0)
        {
            res.number[i] += 10;
            borrow = 1;
        }
        else borrow = 0;
    }
    res.len = get_len(res);
    return res;
}

Tlong add(Tlong a, Tlong b)
{
    Tlong res;
    if (a.sign == b.sign)
    {
        res = add_abs(a,b);
        res.sign=a.sign;
    }
    else if (compare_abs(a, b) == 1)
        {
            res = sub_abs(a, b);
            res.sign = a.sign;
        }
        else if (compare_abs(a, b) == -1)
        {
            res = sub_abs(b, a);
            res.sign = b.sign;
        }
    return res;
}

Tlong sub(Tlong a, Tlong b)
{
    if(b.sign == '-') b.sign = '+';
    else b.sign = '-';
    return add(a, b);
}

Tlong multiply(Tlong a,Tlong b)
{
    Tlong res;
    int rest = 0;
    for (int i = 1; i <= a.len; i++)
        for (int j = 1; j <= b.len; j++)
            res.number[nmax - i - j + 1] += a.number[nmax - i] * b.number[nmax - j];
    for (int i = nmax - 1; i >= 0; i--)
    {
        res.number[i] += rest;
        rest = res.number[i] / 10;
        res.number[i] %= 10;
    }
    res.len = get_len(res);
    if(a.sign != b.sign && !iszero(res)) res.sign='-';
    return res;
}

void print_num(Tlong num)
{
    if (num.sign == '-') cout << '-';
    for (int i = nmax - num.len; i < nmax; i++)
        cout << num.number[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int size;
    cin >> size;
    Tlong res, multiplier, one;
    res.number[nmax - 1] = 1;
    res.len = 1;
    one.number[nmax - 1] = 1;
    one.len = 1;
    multiplier.number[nmax - 1] = 1;
    multiplier.len = 1;
    for (int i = 1; i <= size; i++)
    {
        res = multiply(res, multiplier);
        multiplier = add(multiplier, one);
    }
    print_num(res);
}
