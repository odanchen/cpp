#include<iostream>

using namespace::std;

const int nmax = 201;

struct stash
{
    int num;
    bool check = false;
};


class Tlong
{
public:
    Tlong();
    Tlong(int b);
    
    int get_len();
    void input();
    void print();
    int compare(Tlong &b);
    int compare_to_0();
    Tlong operator+(Tlong &b);
    Tlong operator-(Tlong b);
    Tlong operator*(int b);
    Tlong operator*(Tlong &b);
    Tlong operator/(int b);
    Tlong operator/(Tlong &b);
    Tlong operator%(Tlong &b);
    int operator%(int &b);
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

int Tlong::operator%(int &dil)
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

int count_digits(int num)
{
    int counter = 0;
    while(num > 0)
    {
        counter++;
        num /= 10;
    }
    return counter;
}

void place_blank(int num)
{
    int cnt = count_digits(num);
    for (int i = 0; i < cnt; i++)
        cout << ' ';
}

void read_arr(stash arr[], int len)
{
    for (int i = 1; i <= len; i++)
    {
        cin >> arr[i].num;
        arr[i].check = false;
    }
}

void clear_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = 0;
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len;
    cin >> len;
    stash arr[len + 1];
    read_arr(arr, len);
    int loops[len], len_2 = 0;
    clear_arr(loops, len);
    
    for (int i = 1; i <= len; i++)
    {
        int cur;
        if (arr[i].check == false)
        {
            cur = arr[i].num;
            int idx = cur, cnt = 1;
            while (arr[idx].num != cur)
            {
                cnt++;
                arr[idx].check = true;
                idx = arr[idx].num;
            }
            loops[len_2] = cnt;
            len_2++;
        }
    }
    
    Tlong res(loops[len_2 - 1]);
    for (int i = len_2 - 2; i >= 0; i--)
    {
        res = find_lcm(res, loops[i]);
    }
    res.print();
}
