#include<iostream>

using namespace::std;

const int border = -100000000;

struct compilation
{
    int none = border;
    int left = border;
    int right = border;
    int both = border;
    int value = border;
};

void read_matrix(compilation matrix[][770], int &heigth, int &width)
{
    cin >> heigth >> width;
    
    for (int row = 1; row <= heigth; row++)
        for (int col = 1; col <= width; col++)
            cin >> matrix[row][col].value;
}

void fill_none_path(compilation matrix[][770], int heigth, int width)
{
    for (int col = 2; col < width; col++)
        matrix[1][col].none = matrix[1][col].value;
    
    for (int row = 2; row <= heigth; row++)
    {
        for (int col = 2; col < width; col++)
        {
            int maximum = max(matrix[row - 1][col].none,
                             max(matrix[row - 1][col - 1].none, matrix[row - 1][col + 1].none));
            
            if (maximum != border)
                matrix[row][col].none = maximum + matrix[row][col].value;
        }
    }
}

void fill_left_path(compilation matrix[][770], int heigth, int width)
{
    matrix[1][1].left = matrix[1][1].value;

    for (int row = 2; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            int maximum;
            if (col == 1) maximum = max(matrix[row - 1][col].left,
                                        max(matrix[row - 1][col + 1].left, matrix[row - 1][col + 1].none));
            else
            maximum = max(matrix[row - 1][col].left, max(matrix[row - 1][col - 1].left,
                                                             matrix[row - 1][col + 1].left));
            if (maximum != border)
                matrix[row][col].left = maximum + matrix[row][col].value;
        }
    }
}

void fill_right_path(compilation matrix[][770], int heigth, int width)
{
    matrix[1][width].right = matrix[1][width].value;

    for (int row = 2; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            int maximum;
            if (col == width) maximum = max(matrix[row - 1][col].right,
                                            max(matrix[row - 1][col - 1].right, matrix[row - 1][col - 1].none));
            
            else maximum = max(matrix[row - 1][col].right, max(matrix[row - 1][col - 1].right,
                                                             matrix[row - 1][col + 1].right));
            if (maximum != border)
                matrix[row][col].right = maximum + matrix[row][col].value;
        }
    }
}

void fill_both_path(compilation matrix[][770], int heigth, int width)
{
    matrix[width][1].both = matrix[width][1].right;
    matrix[width][width].both = matrix[width][width].left;
    
    for (int row = width + 1; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
        {
            if (col == 1)
                matrix[row][col].both = max(matrix[row - 1][col + 1].right,
                                            max(matrix[row - 1][col].both, matrix[row - 1][col + 1].both))
                                            + matrix[row][col].value;
            else if (col == width)
                matrix[row][col].both = max(matrix[row - 1][col - 1].left,
                                            max(matrix[row - 1][col].both, matrix[row - 1][col - 1].both))
                                            + matrix[row][col].value;
            else
                matrix[row][col].both = max(matrix[row - 1][col - 1].both,
                                            max(matrix[row - 1][col].both, matrix[row - 1][col + 1].both))
                                            + matrix[row][col].value;
        }
    }
}

void print_matrix(compilation matrix[][770], int heigth, int width)
{
    for (int row = 1; row <= heigth; row++)
    {
        for (int col = 1; col <= width; col++)
            cout << matrix[row][col].both << ' ';
        cout << '\n';
    }
}

int main()
{
    int heigth, width;
    compilation matrix[1026][770];
    
    read_matrix(matrix, heigth, width);
    fill_none_path(matrix, heigth, width);
    fill_left_path(matrix, heigth, width);
    fill_right_path(matrix, heigth, width);
    fill_both_path(matrix, heigth, width);
    
    int ans = matrix[heigth][1].both;
    for (int i = 1; i <= width; i++)
        ans = max(ans, matrix[heigth][i].both);
    
    cout << ans;
}
