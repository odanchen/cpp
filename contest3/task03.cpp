#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int number_of_1s(long long num){
    int sum = 0, maska = 1;
    while (num > 0) {
        if (num & maska) sum++;
        num >>= 1;
    }
    return sum;
}

int main(){
    long long num;
    cin >> num;
    cout << number_of_1s(num);
}
