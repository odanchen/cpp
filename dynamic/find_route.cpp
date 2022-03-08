#include<iostream>

using namespace::std;

const int int_max = 2147483647;

void fill_border(int &heigth, int &width, int matrix[][1002])
{
    int row = 0, col = 0;
    
    for (row = 0, col = 0; col <= width + 1; col++)
        matrix[row][col] = int_max;
    
    for (row = 0, col = width + 1; row <= heigth + 1; row++)
        matrix[row][col] = int_max;
    
    for (row = 0, col = 0; row <= heigth + 1; row++)
        matrix[row][col] = int_max;
    
    for (row = heigth + 1, col = 0; col <= width + 1; col++)
        matrix[row][col] = int_max;
}

void fill_matrix(int &heigth, int &width, int matrix[][1002])
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

void process_matrix(int &heigth, int &width, int matrix[][1002])
{
    for (int row = 1; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            if (row != 1 || col != 1)
                matrix[row][col] = min(matrix[row - 1][col], matrix[row][col - 1]) + matrix[row][col];
        }
    }
}

int find_route(int &heigth, int &width, int matrix[][1002], int steps[][2])
{
    int row = heigth, col = width, cnt = 0;
    
    while(row != 1 || col != 1)
    {
        steps[cnt][0] = row;
        steps[cnt][1] = col;
        
        cnt++;
        
        if (matrix[row - 1][col] > matrix[row][col - 1]) col--;
        else row--;
    }
    
    steps[cnt][0] = row;
    steps[cnt][1] = col;
    
    cnt++;
    
    return cnt;
}

void print_route(int step_count, int step[][2])
{
    for (int i = step_count - 1; i >= 0; i--)
        cout << step[i][0] << ' ' << step[i][1] << '\n';
}

int main()
{
    int heigth, width, matrix[1002][1002], step_count, steps[10000][2];
    
    fill_matrix(heigth, width, matrix);
    process_matrix(heigth, width, matrix);
    
    cout << matrix[heigth][width] << '\n';
    step_count = find_route(heigth, width, matrix, steps);
    cout << step_count << '\n';
    print_route(step_count, steps);
}
