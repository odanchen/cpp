#include<iostream>

using namespace::std;

int main()
{
    char letter_cor;
    int x, y, counter = 0;
    cin >> letter_cor >> y;
    x = letter_cor - 'a' + 1;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if ((abs(x - i) == 1 && abs(y - j) == 2) || (abs(x - i) == 2 && abs(y - j) == 1)) counter++;
        }
    }
    cout << counter;
    return 0;
}
