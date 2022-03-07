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

bool process_matrix(int &heigth, int &width, int matrix[][122])
{
    bool processed = false;
    
    for (int row = 0; row < heigth; row++)
    {
        for (int col = width - 1; col <= 0; col--)
        {
            
        }
    }
    
    return processed;
}

void print_matrix(int &heigth, int &width, int matrix[][122])
{
    for (int row = 0; row <= heigth + 1; row++)
    {
        for (int col = 0; col <= width + 1; col++)
            cout << matrix[row][col] << ' ';
        cout << '\n';
    }
}

int main()
{
    int heigth, width, matrix[122][122];
    
    fill_matrix(heigth, width, matrix);
    print_matrix(heigth, width, matrix);
}
