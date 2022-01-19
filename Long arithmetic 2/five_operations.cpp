#include<iostream>

using namespace::std;

const int nmax = 4000;

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
    num.len = 1;
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

Tlong half_multiply(Tlong a, int b)
{
    Tlong res;
    int p = 0, S;
    if ((b > 0 && a.sign == '-') || (b < 0 && a.sign == '+'))
        res.sign='-';
    b=abs(b);
    for (int i = nmax - 1; i >= nmax - a.len - 10; i--)
    {
        S = a.number[i] * b + p;
        res.number[i] = S % 10;
        p = S / 10;
    }
    res.len = get_len(res);
    return res;
}

Tlong factorial(int num)
{
    Tlong res;
    res.number[nmax - 1] = 1;
    res.len = 1;
    res.sign = '+';
    for (int i = 2; i <= num; i++)
        res = half_multiply(res, i);
    return res;
}

Tlong multiply(Tlong a, Tlong b)
{
    Tlong res;
    int p = 0, temp;
    for (long long i = nmax - 1; i >= nmax - a.len; i--)
        for (long long j = nmax - 1; j >= nmax - b.len - 1; j--)
        {
            temp = a.number[i] * b.number[j] + p + res.number[j + i - (nmax - 1)];
            res.number[j + i - (nmax - 1)] = temp % 10;
            p = temp / 10;
        }
    if (a.sign == b.sign)
        res.sign = '+';
    else
        res.sign = '-';
    res.len = get_len(res);
    return res;
}

Tlong divide(Tlong a, Tlong b, Tlong &rest)
{
    Tlong res;
    rest.len = 1;
    for (int i = nmax - a.len; i < nmax; i++)
    {
        if (rest.len != 1 || rest.number[nmax - 1] != 0) rest.len++;
        for (int j = nmax - rest.len; j < nmax; j++)
            rest.number[j - 1] = rest.number[j];
        rest.number[nmax - 1] = a.number[i];
        int counter = 0;
        while(compare_abs(rest, b) >= 0)
        {
            rest = sub_abs(rest, b);
            counter++;
        }
        res.number[i] = counter;
    }
    res.len = get_len(res);
    rest.len = get_len(rest);
    if (a.sign == b.sign) res.sign = '+';
    else
        res.sign = '-';
    rest.sign = a.sign;
    return res;
}

void print_num(Tlong num)
{
    if (num.len == 0) num.len = 1;
    if (num.len == 1 && num.number[nmax - 1] == 0) num.sign = '+';
    if (num.sign == '-') cout << '-';
    for (int i = nmax - num.len; i < nmax; i++)
        cout << num.number[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Tlong num1, num2, result, ost;
    int num3;
    
    input_number(num1);
    input_number(num2);
    cin >> num3;
    
    
    print_num(num1);
    cout << '+';
    if (num2.sign == '-')
    {
        cout << '(';
        print_num(num2);
        cout << ')';
    }
    else
        print_num(num2);
    cout << '=';
    result = add(num1, num2);
    print_num(result);
    clear_num(result);
    cout << '\n';
    
    
    print_num(num1);
    cout << '-';
    if (num2.sign == '-')
    {
        cout << '(';
        print_num(num2);
        cout << ')';
    }
    else
        print_num(num2);
    cout << '=';
    result = sub(num1, num2);
    print_num(result);
    clear_num(result);
    cout << '\n';
    
    
    print_num(num1);
    cout << '*';
    if (num2.sign == '-')
    {
        cout << '(';
        print_num(num2);
        cout << ')';
    }
    else
        print_num(num2);
    cout << '=';
    result = multiply(num1, num2);
    print_num(result);
    clear_num(result);
    cout << '\n';
    
    
    if (num2.len == 1 && num2.number[nmax - 1] == 0)
        cout << "Division by zero." << '\n';
    else
    {
        print_num(num1);
        cout << '/';
        if (num2.sign == '-')
        {
            cout << '(';
            print_num(num2);
            cout << ')';
        }
        else
            print_num(num2);
        cout << '=';
        result = divide(num1, num2, ost);
        print_num(result);
        cout << ' ' << '(';
        print_num(ost);
        cout << ')';
        clear_num(result);
        cout << '\n';
    }
    
    
    cout << num3 << "!=";
    result = factorial(num3);
    print_num(result);
    
    return 0;
}
