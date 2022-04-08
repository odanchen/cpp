#include<iostream>

using namespace::std;

void fill_1_row(long long matrix[][42], int heigth, int width)
{
    for (int col = 1; col <= width; col++)
        matrix[1][col] = 1;
}

void fill_border(int heigth, int width, long long matrix[][42])
{
    int row = 0, col = 0;
    
    for (row = 0, col = 0; col <= width + 1; col++)
        matrix[row][col] = -1000000000;
    
    for (row = 0, col = width + 1; row <= heigth + 1; row++)
        matrix[row][col] = -1000000000;
    
    for (row = 0, col = 0; row <= heigth + 1; row++)
        matrix[row][col] = -1000000000;
    
    for (row = heigth + 1, col = 0; col <= width + 1; col++)
        matrix[row][col] = -1000000000;
}

void read_matrix(long long matrix[][42], int &heigth, int &width)
{
    cin >> heigth >> width;
    
    for (int row = 1; row <= heigth; row++)
        for (int col = 1; col <= width; col++)
            cin >> matrix[row][col];
    
    fill_border(heigth, width, matrix);
}

void process_matrix(long long matrix[][42], int heigth, int width, long long path_matrix[][42])
{
    for (int row = 2; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            long long maximum = max(max(matrix[row - 1][col - 1], matrix[row - 1][col]), matrix[row - 1][col + 1]);
            matrix[row][col] += maximum;
            
            if (matrix[row - 1][col - 1] == maximum) path_matrix[row][col] += path_matrix[row - 1][col - 1];
            if (matrix[row - 1][col] == maximum) path_matrix[row][col] += path_matrix[row - 1][col];
            if (matrix[row - 1][col + 1] == maximum) path_matrix[row][col] += path_matrix[row - 1][col + 1];
        }
    }
}

void print_matrix(long long matrix[][42], int heigth, int width)
{
    for (int row = 1; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
            cout << matrix[row][col] << ' ';
        cout << '\n';
    }
}

int main()
{
    int heigth, width;
    long long matrix[202][42], path_matrix[202][42] = {0};
    
    read_matrix(matrix, heigth, width);
    fill_1_row(path_matrix, heigth, width);
    
    process_matrix(matrix, heigth, width, path_matrix);
    
    long long maximum = matrix[heigth][1];
    for (int i = 2; i <= width; i++)
        maximum = max(maximum, matrix[heigth][i]);
    
    int ways = 0;
    
    for (int i = 1; i <= width; i++)
        if (matrix[heigth][i] == maximum) ways += path_matrix[heigth][i];
    
    cout << maximum << ' ' << ways;
}
