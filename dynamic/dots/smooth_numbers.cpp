#include<iostream>

using namespace::std;

void fill_matrix(int matrix[][10], int grade)
{
    for (int i = 0; i < 10; i++)
        matrix[0][i] = 1;
    
    for (int row = 1; row < grade; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (col == 0) matrix[row][col] = matrix[row - 1][col] + matrix[row - 1][col + 1];
            else if (col == 9) matrix[row][col] = matrix[row - 1][col] + matrix[row - 1][col - 1];
            else matrix[row][col] = matrix[row - 1][col] + matrix[row - 1][col - 1] + matrix[row - 1][col + 1];
        }
    }
}

int main()
{
    int matrix[20][10] = {0}, grade;
    cin >> grade;
    fill_matrix(matrix, grade);
    
    long long sum = 0;
    for (int i = 0; i < 9; i++)
        sum += matrix[grade - 1][i];
    cout << sum;
}
