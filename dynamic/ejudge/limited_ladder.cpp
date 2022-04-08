#include<iostream>

using namespace::std;

void read_arr(int &jump1, int &jump2, int &len, int arr[])
{
    cin >> jump1 >> jump2;
    len = jump1 + 2 * jump2;
    
    arr[0] = 0;
    for (int i = 1; i <= len; i++)
        cin >> arr[i];
}

void fill_border(int heigth, int width, int matrix[][300])
{
    int row = 0, col = 0;
    
    for (row = 0, col = 0; col <= width + 1; col++)
        matrix[row][col] = 0;
    
    for (row = 0, col = width + 1; row <= heigth + 1; row++)
        matrix[row][col] = 0;
    
    for (row = 0, col = 0; row <= heigth + 1; row++)
        matrix[row][col] = 0;
    
    for (row = heigth + 1, col = 0; col <= width + 1; col++)
        matrix[row][col] = 0;
}

void fill_matrix(int jump1, int jump2, int matrix[][300], int carrots[])
{
    fill_border(jump2 + 1, jump1 + 1, matrix);
    
    for (int row = 1; row <= jump2; row++)
        for (int col = 1; col <= jump1; col++)
            matrix[row][col] = carrots[col  - 1 + (row - 1) * 2];
}

void process_matrix(int heigth, int width, int matrix[][300])
{
    for (int row = 1; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            if ((row != 1 || col != 1) && (row != 2 || col != 1) && (row != 1 || col != 2))
            {
                if (matrix[row - 1][col] == 0 && matrix[row][col - 1] == 0) matrix[row][col] = 0;
                else if (matrix[row][col] == 0) matrix[row][col] = 0;
                else if (matrix[row - 1][col] == 0) matrix[row][col] = matrix[row][col - 1] + matrix[row][col];
                else if (matrix[row][col - 1] == 0) matrix[row][col] = matrix[row - 1][col] + matrix[row][col];
                else matrix[row][col] = max(matrix[row - 1][col], matrix[row][col - 1]) + matrix[row][col];
            }
        }
    }
}

int main()
{
    int jump1, jump2, len, carrots[400];
    int matrix[300][300];
    
    read_arr(jump1, jump2, len, carrots);
    
    fill_matrix(jump1 + 1, jump2 + 1, matrix, carrots);
    process_matrix(jump2 + 1, jump1 + 1, matrix);
    
    if (matrix[jump2 + 1][jump1 + 1] == 0 && matrix[jump2][jump1 + 1] == 0 && matrix[jump2 + 1][jump1] == 0)
        cout << "experiment failed";
    else cout << matrix[jump2 + 1][jump1 + 1];
}
