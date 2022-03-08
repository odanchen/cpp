#include<iostream>

using namespace::std;

void fill_border(int matrix[][10])
{
    int heigth = 8, width = 8;
    int row = 0, col = 0;
    
    for (row = 0, col = 0; col <= width + 1; col++)
        matrix[row][col] = 2000;
    
    for (row = 0, col = width + 1; row <= heigth + 1; row++)
        matrix[row][col] = 2000;
    
    for (row = 0, col = 0; row <= heigth + 1; row++)
        matrix[row][col] = 2000;
    
    for (row = heigth + 1, col = 0; col <= width + 1; col++)
        matrix[row][col] = 2000;
}

void fill_matrix(int matrix[][10])
{
    int heigth = 8, width = 8;
    
    fill_border(matrix);
    
    for (int row = 1; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            cin >> matrix[row][col];
        }
    }
}

void process_matrix(int matrix[][10])
{
    int heigth = 8, width = 8;
    
    for (int row = heigth; row >= 1; row--)
    {
        for (int col = 1; col <= width; col++)
        {
            if (row != heigth || col != 1)
            {
                matrix[row][col] = min(matrix[row + 1][col],
                                    min(matrix[row][col - 1], matrix[row + 1][col - 1])) + matrix[row][col];
            }
        }
    }
}

int main()
{
    int matrix[10][10];
    
    fill_matrix(matrix);
    process_matrix(matrix);
    
    cout << matrix[1][8];
}
