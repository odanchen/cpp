#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find_mask(int num) {
    int mask = 1;
    while(num > mask) mask <<= 1;
    return mask;
}

int dig_count(int num) {
    int counter = 0;
    while(num > 0) {
        num >>= 1;
        counter++;
    }
    return counter;
}

int max_num(int num) {
    int max_number = num, counter = dig_count(num), mask = find_mask(num);
    for (int i = 0; i < counter; i++) {
        num <<= 1;
        if (num & mask) num++;
        num = num & (~mask);
        if (num > max_number) max_number = num;
    }
    return max_number;
}

int main()
{
    int num;
    cin >> num;
    cout << max_num(num);
}
