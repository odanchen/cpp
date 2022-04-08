#include<iostream>

using namespace::std;

string encrypt(int num)
{
    string S;
    string grade1[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string grade2[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string grade3[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    
    S.insert(0, grade1[num % 10]);
    num -= num % 10;
    
    S.insert(0, grade2[num % 100 / 10]);
    num -= num % 100;
    
    S.insert(0, grade3[num % 1000 / 100]);
    num -= num % 1000;
    
    while (num > 0)
    {
        S.insert(0, "M");
        num -= 1000;
    }
    
    return S;
}

int main()
{
    int num;
    cin >> num;
    cout << encrypt(num);
}
