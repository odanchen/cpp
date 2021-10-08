#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sum, xor_sum;
    cin >> sum >> xor_sum;
    if (xor_sum > sum) cout << -1;
    else {
    cout << ((sum - xor_sum) >> 1) << " " << "\n";
    cout << ((sum - xor_sum) >> 1) + xor_sum;
    }
}
