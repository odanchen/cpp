#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int Max, notMax1, notMax2;
    
    cin >> Max >> notMax1 >> notMax2;
    
    if (notMax1 > Max || notMax2 > Max) cout << 0 << '\n';
    else cout << Max - max(notMax1, notMax2) + 1 << '\n';
}
