#include<iostream>

using namespace::std;

int res(int num)
{
    int num1 = 2, num2 = 4, num3 = 7, cur = 13;
    
    if (num == 1) return num1;
    if (num == 2) return num2;
    if (num == 3) return num3;
    
    for (int i = 4; i < num; i++)
    {
        num1 = num2;
        num2 = num3;
        num3 = cur;
        cur = num1 + num2 + num3;
    }
    
    return cur;
}

int main()
{
    int num;
    cin >> num;
    cout << res(num);
}
