#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int healed_code(int num) {
    int mask = 1;
    while (not(num & mask)) mask <<= 1;
    while (num & mask) {
        num = (num & (~mask));
        mask <<= 1;
    }
    return num;
}

int main()
{
    int num, cownt, doomed_cows = 0;
    cin >> cownt;
    for (int i = 0; i < cownt; i++) {
        cin >> num;
        if (healed_code(num) == 0) doomed_cows++;
        else cout << healed_code(num) << " ";
    }
    cout << "\n" << doomed_cows;
}
