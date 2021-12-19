#include<iostream>

using namespace::std;

bool is_correct_num(int num, int digits[])
{
    int len = 0;
    for (int i = 0; i < 4; i++)
    {
        digits[i] = 0;
    }
    int i = 0;
    while(num > 0)
    {
        digits[i] = (num % 10);
        num /= 10;
        len++;
        i++;
    }
    for (int i = 0; i < len - 1; i++)
        if (digits[i] <= digits[i + 1]) return false;
    return true;
}

int main()
{
    int num, digits[4];
    cin >> num;
    while(not(is_correct_num(num, digits)))
        num++;
    cout << num;
    return 0;
}
