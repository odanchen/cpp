#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int number_of_1s(unsigned int num) {
    int sum = 0, maska = 1;
    while (num > 0) {
        if (num & maska) sum++;
        num >>= 1;
    }
    return sum;
}

int number_of_0s(unsigned int num) {
    int sum = 0, maska = 1;
    while (num > 0) {
        if (not((num & maska))) sum ++;
        num >>= 1;
    }
    return sum;
}

int minimal_num(unsigned int num) {
    if (number_of_1s(num) == 1) return 1;
    return (pow(2, number_of_1s(num)) - 1);
}

int maximum_num(unsigned int num) {
    int maxnum = minimal_num(num);
    return (maxnum << number_of_0s(num));
}

int main() {
    unsigned int num;
    cin >> num;
    cout << (maximum_num(num) - minimal_num(num));
}
