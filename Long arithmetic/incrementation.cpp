#include<iostream>

using namespace::std;

const int nmax = 10001;

struct Tlong
{
    char sign = '+';
    int number[nmax] = {0};
    int len = 1;
};

void clear_num(Tlong &num)
{
    for (int i = nmax - num.len; i < nmax; i++)
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

Tlong abs_plus(Tlong a, Tlong b)
{
    Tlong res;
    res.sign = '+';
    clear_num(res);
    for (int i = 0; i < nmax; i++)
        res.number[i] = a.number[i];
    int p = 0;
    for (int i = nmax - 1; i > nmax - max(a.len, b.len) - 1; i--)
    {
        res.number[i] = (a.number[i] + b.number[i] + p) % 10;
        p = (a.number[i] + b.number[i] + p) / 10;
    }
    if (res.number[nmax - max(a.len, b.len) - 1] == 1)
        res.len = max(a.len, b.len) + 1;
    else
        res.len = max(a.len, b.len);
    return res;
}

Tlong add_abs(Tlong a, Tlong b)
{
    Tlong res;
    int sum, rest = 0;
    int len = max(a.len,b.len);
        res.len = len;
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
    Tlong num, res, addition;
    int repeats;
    clear_num(addition);
    addition.len = 1;
    addition.sign = '+';
    addition.number[nmax - 1] = 1;
    cin >> repeats;
    for (int i = 0; i < repeats; i++)
    {
        input_number(num);
        res = add(num, addition);
        print_num(res);
        clear_num(num);
        cout << "\n";
    }
}
