#include<iostream>

using namespace::std;

const int nmax = 100;

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
    void operator=(int b);
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

void Tlong::operator=(int b)
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

void fill_map(int map[][3])
{
    map[0][0] = 4; map[0][1] = 6; map[0][2] = 10;
    map[1][0] = 8; map[1][1] = 6; map[1][2] = 10;
    map[2][0] = 7; map[2][1] = 9; map[2][2] = 10;
    map[3][0] = 4; map[3][1] = 8; map[3][2] = 10;
    map[4][0] = 0; map[4][1] = 3; map[4][2] = 9;
    map[5][0] = 10;map[5][1] = 10;map[5][2] = 10;
    map[6][0] = 0; map[6][1] = 1; map[6][2] = 7;
    map[7][0] = 2; map[7][1] = 6; map[7][2] = 10;
    map[8][0] = 1; map[8][1] = 3; map[8][2] = 10;
    map[9][0] = 4; map[9][1] = 2; map[9][2] = 10;
}

void prepare_matrix(int num, Tlong matrix[][11])
{
    for (int i = 0; i < 10; i++)
        matrix[0][i] = 1;
    
    for (int i = 0; i < num; i++)
        matrix[i][10] = 0;
}

Tlong process_node(Tlong matrix[][11], int row, int col, int map[][3])
{
    return (matrix[row - 1][map[col][0]] + matrix[row - 1][map[col][1]] + matrix[row - 1][map[col][2]]);
}

Tlong ways_to_form(int num)
{
    int map[10][3];
    Tlong matrix[100][11];
    Tlong sum;
    fill_map(map);
    prepare_matrix(num, matrix);
    
    for (int row = 1; row < num; row++)
        for (int col = 0; col < 10; col++)
            matrix[row][col] = process_node(matrix, row, col, map);

    for (int i = 0; i < 10; i++)
        if (i != 0 && i != 8)
            sum = sum + matrix[num - 1][i];
    
    return sum;
}

int main()
{
    int num;
    cin >> num;
    Tlong res;
    res = ways_to_form(num);
    
    res.print();
}
