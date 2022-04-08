#include<iostream>

using namespace::std;

bool is_valid(int black, int white)
{
    if (black > (white * 3 + 1)) return false;
    if (white > (black * 3 + 1)) return false;
    return true;
}

void print_matrix(int len, int heigth, char matrix[][210])
{
    cout << heigth << ' ' << len << '\n';
    for (int row = 0; row < heigth; row++)
    {
        for (int col = 0; col < len; col++)
        {
            if (matrix[row][col] == 0) cout << '.';
            else cout << matrix[row][col];
        }
        cout << '\n';
    }
}

int main()
{
    int black, white;
    char matrix[3][210] = {0}, cur;
    cin >> white >> black;
    int len = min(black, white) * 2 + 1, height = 3, bcount = 0, wcount = 0;
    
    if (not(is_valid(black, white)))
    {
        cout << -1;
        return 0;
    }
    
    if (white > black) cur = 'W';
    else cur = 'B';
    
    for (int i = 0; i < len; i++)
    {
        if (not((cur == 'B' && bcount == black) || (cur == 'W' && wcount == white)))
            matrix[1][i] = cur;
        if (cur == 'B')
        {
            bcount++;
            cur = 'W';
        }
        else
        {
            wcount++;
            cur = 'B';
        }
    }
    
    if (black != bcount) cur = 'B';
    else if (white != wcount) cur = 'W';
    else
    {
        print_matrix(len, height, matrix);
        return 0;
    }
    
    int curmax = max(black, white), curcnt = max(wcount, bcount);
    
    for (int i = 0; i < len; i++)
    {
        if((curmax > curcnt) && (matrix[1][i] != cur))
        {
            matrix[0][i] = cur;
            curcnt++;
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        if((curmax > curcnt) && (matrix[1][i] != cur))
        {
            matrix[2][i] = cur;
            curcnt++;
        }
    }
    
    print_matrix(len, height, matrix);
}
