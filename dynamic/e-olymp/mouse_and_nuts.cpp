#include<iostream>

using namespace::std;

void fill_border(int heigth, int width, int matrix[][102])
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

void fill_matrix(int &heigth, int &width, int matrix[][102])
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

void process_matrix(int heigth, int width, int matrix[][102])
{
    for (int row = heigth; row >= 1; row--)
    {
        for (int col = 1; col <= width; col++)
        {
            if (row != heigth || col != 1)
            {
                matrix[row][col] = max(matrix[row][col - 1], matrix[row + 1][col]) + matrix[row][col];
            }
        }
    }
}

string mark_route(int heigth, int width, int matrix[][102])
{
    int row = 1, col = width;
    string ans = "";
    
    while(row != heigth || col != 1)
    {
        
        if (matrix[row + 1][col] < matrix[row][col - 1])
        {
            col--;
            ans += "R";
        }
        else
        {
            row++;
            ans += "F";
        }
    }
    
    for (int i = 0; i < ans.size() / 2; i++)
    {
        swap(ans[i], ans[ans.size() - i - 1]);
    }
    
    return ans;
}

int main()
{
    int matrix[102][102], heigth, width;
    
    fill_matrix(heigth, width, matrix);
    
    process_matrix(heigth, width, matrix);
    cout << mark_route(heigth, width, matrix);
}
