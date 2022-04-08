#include<iostream>

using namespace::std;

const int nmax = 1200;

struct remainders
{
    int num;
    int quantity = 0;
};

class Tlong
{
public:
    Tlong();
    Tlong(int b);
    
    int get_len();
    void input();
    void print();
    void print_fraction(int &len);
    int compare(Tlong &b);
    int compare_to_0();
    Tlong operator+(Tlong &b);
    Tlong operator+(int &b);
    Tlong operator-(Tlong b);
    Tlong operator*(int b);
    Tlong operator*(Tlong &b);
    Tlong operator/(int b);
    Tlong operator/(Tlong &b);
    Tlong operator%(Tlong &b);
    int operator%(int b);
    Tlong operator++();
    Tlong operator--();
private:
    char sign = '+';
    int number[nmax + 1];
    int len = 1;
    Tlong add_abs(Tlong &b);
    Tlong sub_abs(Tlong &b);
    void clear_num();
    int compare_abs(Tlong &b);
};

Tlong::Tlong()
{
    sign = '+';
    len = 1;
    for (int i = 0; i < nmax; i++)
        number[i] = 0;
}

Tlong::Tlong(int b)
{
    if (b < 0) sign = '-';
    else sign = '+';
    
    b = abs(b);
    
    for (int i = 0; i < nmax; i++)
        number[i] = 0;
    
    int cnt = 0;
    
    while(b != 0)
    {
        cnt++;
        number[nmax - cnt] = b % 10;
        b /= 10;
    }
    len = cnt;
}

void Tlong::clear_num()
{
    sign = '+';
    for (int i = 0; i <= nmax; i++)
        number[i] = 0;
    len = 1;
}

int Tlong::get_len()
{
    int i = 0;
    while(number[i] == 0 && i < nmax) i++;
    if (i == nmax) return 1;
    return nmax - i;
}

void Tlong::input()
{
    clear_num();
    string S;
    cin >> S;
    if (S[0] == '-' || S[0] == '+')
    {
        sign = S[0];
        S.erase(0, 1);
    }
    else
        sign = '+';
    int length = (int)S.size();
    for (int i = 0; i < length - 1 && S[0] == '0'; i++)
        S.erase(0, 1);
    len = (int)S.size();
    if (S[0] == '0')
        sign = '+';
    int k = 0;
    for(int i = nmax - len; i < nmax; i++)
    {
        number[i] = S[k] - '0';
        k++;
    }
}

void Tlong::print()
{
    if (len == 0) len = 1;
    if (len == 1 && number[nmax - 1] == 0) sign = '+';
    if (sign == '-') cout << '-';
    for (int i = nmax - len; i < nmax; i++)
        cout << number[i];
}

int Tlong::compare_abs(Tlong &b)
{
    if (len > b.len) return 1;
    if (len < b.len) return -1;
    for (int i = nmax - len; i < nmax; i++)
    {
        if (number[i] > b.number[i]) return 1;
        if (number[i] < b.number[i]) return -1;
    }
    return 0;
}

int Tlong::compare(Tlong &b)
{
    if (sign == '+' && b.sign == '-') return 1;
    if (sign == '-' && b.sign == '+') return -1;
    if (sign == '+' && b.sign == '+') return compare_abs(b);
    if (sign == '-' && b.sign == '-') return -compare_abs(b);
    return 0;
}

Tlong Tlong::add_abs(Tlong &b)
{
    Tlong res;
    int sum, rest = 0;
    int length = max(len, b.len);
    for (int i = nmax - 1; i >= nmax - length - 1; i--)
    {
        sum = number[i] + b.number[i] + rest;
        res.number[i] = sum % 10;
        rest = sum / 10;
    }
    res.len = res.get_len();
    return res;
}

Tlong Tlong::sub_abs(Tlong &b)
{
    Tlong res;
    int borrow = 0;
    int length = max(len, b.len);
    for (int i = nmax - 1; i >= nmax - length; i--)
    {
        res.number[i] = number[i] - b.number[i] - borrow;
        if (res.number[i] < 0)
        {
            res.number[i] += 10;
            borrow = 1;
        }
        else borrow = 0;
    }
    res.len = res.get_len();
    return res;
}

Tlong Tlong::operator+(Tlong &b)
{
    Tlong res;
    if (sign == b.sign)
    {
        res = add_abs(b);
        res.sign = sign;
    }
    else if (compare_abs(b) == 1)
        {
            res = sub_abs(b);
            res.sign = sign;
        }
        else if (compare_abs(b) == -1)
        {
            res = b.sub_abs(*this);
            res.sign = b.sign;
        }
    return res;
}

Tlong Tlong::operator+(int &b)
{
    Tlong adder(b);
    return *this + adder;
}

Tlong Tlong::operator-(Tlong b)
{
    if (b.sign == '-')
        b.sign = '+';
    else
        b.sign = '-';
    return *this + b;
}

Tlong Tlong::operator++()
    {
        int i=1;
        if (sign=='+')
        {
            while(number[nmax-i]==9)
            {
                number[nmax-i]=0;
                ++i;
            }
            ++number[nmax-i];
        }
        else
        {
            while (number[nmax-i]==0)
            {
                number[nmax-i]=9;
                ++i;
            }
            --number[nmax-i];
            if(len == 1 && number[nmax-1] == 0) sign='+';
        }
        if (i>len) ++len;
        return *this;
    }

Tlong Tlong::operator--()
{
    Tlong one;
    one.number[nmax - 1] = 1;
    one.len = 1;
    *this = *this - one;
    return *this;
}

Tlong Tlong::operator*(int b)
{
    Tlong res;
    int p = 0, S;
    if ((b > 0 && sign == '-') || (b < 0 && sign == '+'))
        res.sign='-';
    b=abs(b);
    for (int i = nmax - 1; i >= nmax - len - 10; i--)
    {
        S = number[i] * b + p;
        res.number[i] = S % 10;
        p = S / 10;
    }
    res.len = res.get_len();
    return res;
}

Tlong Tlong::operator*(Tlong &b)
{
    Tlong res;
    int p = 0, temp;
    for (long long i = nmax - 1; i >= nmax - len; i--)
        for (long long j = nmax - 1; j >= nmax - b.len - 1; j--)
        {
            temp = number[i] * b.number[j] + p + res.number[j + i - (nmax - 1)];
            res.number[j + i - (nmax - 1)] = temp % 10;
            p = temp / 10;
        }
    if (sign == b.sign)
        res.sign = '+';
    else
        res.sign = '-';
    res.len = res.get_len();
    return res;
}

Tlong Tlong::operator/(Tlong &b)
{
    Tlong res;
    Tlong rest;
    rest.len = 1;
    for (int i = nmax - len; i < nmax; i++)
    {
        if (rest.len != 1 || rest.number[nmax - 1] != 0) rest.len++;
        for (int j = nmax - rest.len; j < nmax; j++)
            rest.number[j - 1] = rest.number[j];
        rest.number[nmax - 1] = number[i];
        int counter = 0;
        while(rest.compare_abs(b) >= 0)
        {
            rest = rest.sub_abs(b);
            counter++;
        }
        res.number[i] = counter;
    }
    res.len = res.get_len();
    if (sign == b.sign) res.sign = '+';
    else
        res.sign = '-';
    return res;
}

Tlong Tlong::operator/(int b)
{
    Tlong res;
    int rest = 0;
    if ((sign == '-' && b >= 0) || (sign == '+' && b <= 0))
        res.sign = '-';
    b = abs(b);
    for (int i = nmax - len; i < nmax; i++)
    {
        rest = rest * 10 + number[i];
        res.number[i] = rest / b;
        
        rest = rest % b;
    }
    res.len = res.get_len();
    return res;
}

Tlong Tlong::operator%(Tlong &b)
{
    Tlong res;
    Tlong rest;
    rest.len = 1;
    for (int i = nmax - len; i < nmax; i++)
    {
        if (rest.len != 1 || rest.number[nmax - 1] != 0) rest.len++;
        for (int j = nmax - rest.len; j < nmax; j++)
            rest.number[j - 1] = rest.number[j];
        rest.number[nmax - 1] = number[i];
        int counter = 0;
        while(rest.compare_abs(b) >= 0)
        {
            rest = rest.sub_abs(b);
            counter++;
        }
        res.number[i] = counter;
    }
    rest.len = rest.get_len();
    rest.sign = sign;
    return rest;
}

int Tlong::operator%(int dil)
{
    int remainder = 0;
    for (int i = nmax - len; i < nmax; i += 0)
    {
        if (remainder < dil)
        {
            remainder *= 10;
            remainder += number[i];
            i++;
        }
        else
            remainder %= dil;
    }
    return remainder % dil;
}

int Tlong::compare_to_0()
{
    if (len == 0) len = 1;
    if (len == 1 && number[nmax - 1] == 0) sign = '+';
    
    if (sign == '-') return -1;
    if (len == 1 && number[nmax - 1] == 0) return 0;
    return 1;
}

Tlong find_gcd(Tlong a, Tlong b)
{
    Tlong rest = a;
    while (rest.compare_to_0() != 0)
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

Tlong find_lcm(Tlong &a, int &b)
{
    Tlong mlt, gcd, res;
    Tlong copy(b);
    mlt = a * b;
    gcd = find_gcd(a, b);
    res = mlt / gcd;
    return res;
}

int count_mlt(Tlong num, int mlt)
{
    int cnt = 0;
    while(num % mlt == 0)
    {
        cnt++;
        num = num / mlt;
    }
    return cnt;
}

int count_rest_len(Tlong num, Tlong dil)
{
    int fives1 = 0, fives2 = 0, twos1 = 0, twos2 = 0;
    
    fives1 = count_mlt(num, 5);
    fives2 = count_mlt(dil, 5);
    twos1 = count_mlt(num, 2);
    twos2 = count_mlt(dil, 2);
    
    if (max(fives2 - fives1, twos2 - twos1) <= 0)
        return 0;
    else
        return max(fives2 - fives1, twos2 - twos1);
}

Tlong find_real_part(int rest_len, Tlong num, Tlong dil)
{
    Tlong mlt (1), real_part;
    for (int i = 0; i < rest_len; i++)
        mlt = mlt * 10;
    
    num = num * mlt;
    real_part = num / dil;
    real_part = real_part % mlt;
    return real_part;
}

Tlong find_period(int rest_len, Tlong num, Tlong dil)
{
    Tlong ans(0);
    
    for (int i = 0; i < rest_len; i++)
        num = num * 10;
    
    num = num * 10;
    Tlong res;
    res = num / dil;
    int period = res % 10;
    if (period == 0)
        return 0;
    
    ans = ans + period;
    
    int cur = 0;
    while (cur != period)
    {
        num = num * 10;
        res = num / dil;
        cur = res % 10;
        if (cur != period)
        {
            ans = ans * 10;
            ans = ans + cur;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Tlong num, dil, int_part, real_part, period;
    int rest_len;
    
    num.input();
    dil.input();
    
    int_part = num / dil;
    rest_len = count_rest_len(num, dil);
    real_part = find_real_part(rest_len, num, dil);
    period = find_period(rest_len, num, dil);
    
    int_part.print();
    
    if (rest_len != 0)
    {
        cout << '.';
        int len = real_part.get_len();
        if (rest_len != len)
            for (int i = 0; i < rest_len - len; i++)
                cout << 0;
        real_part.print();
    }
    
    if (rest_len == 0 && period.compare_to_0() != 0)
        cout << '.';
    
    if (period.compare_to_0() != 0)
    {
        cout << '(';
        period.print();
        cout << ')';
    }
}
