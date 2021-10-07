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

bool is_sick(int num) {
    int counter = dig_count(num), mask = find_mask(num), prev_dig = (num & (mask << 1));
    for (int i = 0; i < counter; i++) {
        num <<= 1;
        if ((num & mask) && prev_dig) return true;
        if (num & mask) prev_dig = 1;
        else prev_dig = 0;
        if (num & mask) num++;
        num = num & (~mask);
    }
    return false;
}

int position(int num) {
    int counter = dig_count(num), mask = find_mask(num), prev_dig = (num & (mask << 1)), invert_pos = 0;
    for (int i = 0; i < counter; i++) {
        num <<= 1;
        if ((num & mask) && prev_dig) return counter - (invert_pos - 1);
        if (num & mask) prev_dig = 1;
        else prev_dig = 0;
        if (num & mask) num++;
        num = num & (~mask);
        invert_pos++;
    }
    return 0;
}

int healed_code(int num) {
    int mask = 1 << (position(num) - 1);
    while (num & mask) {
        num = (num & (~mask));
        mask >>= 1;
    }
    return num;
}

int main()
{
    int num, cownt, doomed_cows = 0;
    cin >> cownt;
    for (int i = 0; i < cownt; i++) {
        cin >> num;
        if (not(is_sick(num))) cout << num << " ";
        else {
            if(healed_code(num) == 0) doomed_cows++;
            else cout << healed_code(num) << " ";
        }
    }
    cout << "\n" << doomed_cows;
}
