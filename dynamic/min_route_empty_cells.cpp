#include<iostream>

using namespace::std;

void fill_border(int &heigth, int &width, int matrix[][122])
{
    int row = 0, col = 0;
    
    for (row = 0, col = 0; col <= width + 1; col++)
        matrix[row][col] = -1;
    
    for (row = 0, col = width + 1; row <= heigth + 1; row++)
        matrix[row][col] = -1;
    
    for (row = 0, col = 0; row <= heigth + 1; row++)
        matrix[row][col] = -1;
    
    for (row = heigth + 1, col = 0; col <= width + 1; col++)
        matrix[row][col] = -1;
}

void fill_matrix(int &heigth, int &width, int matrix[][122])
{
    cin >> heigth >> width;
    
    fill_border(heigth, width, matrix);
    
    for (int row = 1; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            cin >> matrix[row][col];
        }
    }
}

void process_matrix(int &heigth, int &width, int matrix[][122])
{
    for (int row = 1; row <= heigth; row++)
    {
        for (int col = width; col >= 1; col--)
        {
            if (row != 1 || col != width)
            {
                if (matrix[row - 1][col] == -1 && matrix[row][col + 1] == -1) matrix[row][col] = -1;
                else if (matrix[row][col] == -1) matrix[row][col] = -1;
                else if (matrix[row - 1][col] == -1) matrix[row][col] = matrix[row][col + 1] + matrix[row][col];
                else if (matrix[row][col + 1] == -1) matrix[row][col] = matrix[row - 1][col] + matrix[row][col];
                else matrix[row][col] = max(matrix[row - 1][col], matrix[row][col + 1]) + matrix[row][col];
            }
        }
    }
}

void print_matrix(int &heigth, int &width, int matrix[][122])
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
    int heigth, width, matrix[122][122];
    
    fill_matrix(heigth, width, matrix);
    if (matrix[heigth][1] == -1) cout << "No answer";
    else
    {
        process_matrix(heigth, width, matrix);
    
        if (matrix[heigth][1] == -1 && matrix[heigth - 1][1] == -1 && matrix[heigth][2] == -1) cout << "No answer";
        else cout << matrix[heigth][1];
    }
}
