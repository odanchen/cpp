#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int result= 0, counter = 0;
    char num;
    bool is_negative = false;
    do {
        cin >> num;
        if (counter == 0 && num == '1') is_negative = true;
        counter++;
        result <<= 1;
        if (num == '1') result += 1;
    } while (cin.peek() != '\n');
    if (is_negative) {
        result = ~result;
        result = result & (~(~0 << counter));
        result = result + 1;
        result = -result;
    }
    cout << result;
}
