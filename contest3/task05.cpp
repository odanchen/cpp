#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, entered_sum, all = 0, entered;
    cin >> num;
    for (int i = 1; i <= num; i++) {
        all ^= i;
    }
    for (int i = 1; i < num; i++) {
        cin >> entered;
        entered_sum ^= entered;
    }
    cout << (entered_sum ^ all);
}
