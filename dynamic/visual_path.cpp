#include<iostream>

using namespace::std;

void fill_border(int size, int matrix[][252])
{
    int row = 0, col = 0;
    
    for (row = 0, col = 0; col <= size + 1; col++)
        matrix[row][col] = 2000;
    
    for (row = 0, col = size + 1; row <= size + 1; row++)
        matrix[row][col] = 2000;
    
    for (row = 0, col = 0; row <= size + 1; row++)
        matrix[row][col] = 2000;
    
    for (row = size + 1, col = 0; col <= size + 1; col++)
        matrix[row][col] = 2000;
}

void fill_matrix(int &size, int matrix[][252])
{
    cin >> size;
    
    fill_border(size, matrix);
    
    for (int row = 1; row <= size; row++)
    {
        string S;
        cin >> S;
        
        for (int col = 1; col <= size; col++)
        {
            matrix[row][col] = S[col - 1] - '0';
        }
    }
}

void process_matrix(int size, int matrix[][252])
{
    for (int row = 1; row <= size; row++)
    {
        for (int col = 1; col <= size; col++)
        {
            if (row != 1 || col != 1)
            {
                matrix[row][col] = min(matrix[row - 1][col], matrix[row][col - 1]) + matrix[row][col];
            }
        }
    }
}

void mark_route(int size, int matrix[][252])
{
    int row = size, col = size;
    
    while(row != 1 || col != 1)
    {
        matrix[row][col] = '#';
        
        if (matrix[row - 1][col] > matrix[row][col - 1]) col--;
        else row--;
    }
    
    matrix[1][1] = '#';
}

void fill_visual_matrix(int size, int matrix[][252])
{
    for (int row = 1; row <= size; row++)
    {
        for (int col = 1; col <= size; col++)
        {
            if (matrix[row][col] != '#')
            {
                matrix[row][col] = '.';
            }
        }
    }
}

void print_matrix(int size, int matrix[][252])
{
    for (int row = 1; row <= size; row++)
    {
        for (int col = 1; col <= size; col++)
            cout << (char)matrix[row][col];
        cout << '\n';
    }
}

int main()
{
    int matrix[252][252], size;
    
    fill_matrix(size, matrix);
    
    process_matrix(size, matrix);
    mark_route(size, matrix);
    fill_visual_matrix(size, matrix);
    print_matrix(size, matrix);

}
