#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_number(unsigned int num) {
    unsigned int mask, counter = 1;
    mask = 1 << 31;
    num++;
    while (not(num & mask)) {
        num <<= 1;
        counter++;
    }
    num <<= 1;
    for(int i = 32 - counter; i > 0; i--) {
        if (num & mask) cout << "7";
        else cout << "1";
        num <<= 1;
    }
    cout << "\n";
}

int main() {
    unsigned int num;
    cin >> num;
    print_number(num);
}
