#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_binary(int num, int grade){
    int mask = 1;
    mask <<= grade;
    for (int i = 0; i < grade; i++) {
        num <<= 1;
        if (num & mask) cout << 1;
        else cout << 0;
    }
}

int main()
{
    int num, grade;
    cin >> num >> grade;
    print_binary(num, grade);
}
