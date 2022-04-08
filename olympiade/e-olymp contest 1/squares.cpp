#include<iostream>

using namespace::std;

const int maxsize = 10000;

int count_dots(int matrix[][maxsize], int top, int left, int k)
{
    int sum = 0;
    for (int row = top; row < top + k; row++)
    {
        for (int col = left; col < left + k; col++)
        {
            sum += matrix[row][col];
        }
    }
    return sum;
}

int main()
{
    int m, n, k;
    cin >> n >> m >> k;
    int matrix[maxsize][maxsize] = {0}, dot_counter[20] = {0}, counter_len = k * k + 1;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        matrix[x - 1][y - 1] = 1;
    }
    for (int row = 0; row <= m - k; row++)
    {
        for (int col = 0 ; col <= m - k; col++)
        {
            dot_counter[count_dots(matrix, row, col, k)]++;
        }
    }
    for (int i = 0; i < counter_len; i++)
        cout << dot_counter[i] << " ";
}
