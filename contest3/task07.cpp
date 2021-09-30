#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char find_missing_letter(int num) {
    char letter, missing = 0;
    for(int i = 0; i < num; i++) {
        cin >> letter;
        missing = missing ^ letter;
    }
    return missing;
}

int main(){
    int num;
    char missing_letter;
    cin >> num;
    missing_letter = find_missing_letter(num);
    if (missing_letter == 0) cout << "Ok";
    else cout << missing_letter;
}
