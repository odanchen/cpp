#include<iostream>

using namespace::std;

int main()
{
    int cor[3], len = 3;
    cin >> cor[0] >> cor[1] >> cor[2];
    sort(cor, cor + len);
    if (cor[0] >= 0)
        cout << cor[2] * 2;
    else if (cor[2] <= 0)
        cout << abs(cor[0]) * 2;
    else
        cout << abs(cor[0] - cor[2]) * 2;
    return 0;
}
