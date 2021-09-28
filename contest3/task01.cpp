#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int set_k_bit_to_1(long long num, int k) {
    int mask = 1 << (k - 1);
    return (num | mask);
}

int invert_kths_bit(long long num, int k) {
    int mask = 1 << (k - 1);
    return (num & ~mask) | (~num & mask);
}

int get_kths_bit(long long num, int k) {
    return (num >> (k - 1)) & 1;
}

int zero_last_k_bits(long long num, int k) {
    return (num >> k) << k;
}

int zero_all_beside_last(long long num, int k) {
    return num & ((1 << k) - 1);
}

int main(){
    long long num;
    int k;
    cin >> num >> k;
    cout << get_kths_bit(num, k) << "\n";
    cout << set_k_bit_to_1(num, k) << "\n";
    cout << invert_kths_bit(num, k) << "\n";
    cout << zero_last_k_bits(num, k) << "\n";
    cout << zero_all_beside_last(num, k) << "\n";
}
