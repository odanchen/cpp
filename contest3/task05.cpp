#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_missing_num(int num) {
    int constnum = num, lost_num = 1;
    for (int i = 2; i <= constnum; i++) {
        lost_num ^= num;
        lost_num ^= i;
        cin >> num;
    }
    if (num == constnum - 1) lost_num = constnum;
    return lost_num;
}

int main() {
    int num;
    cin >> num;
    cout << find_missing_num(num);
}
