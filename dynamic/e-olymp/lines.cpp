#include<iostream>

using namespace::std;

struct cord
{
    int row;
    int col;
};

void read_matrix(int &size, char matrix[][50], cord &start, cord &finish)
{
    cin >> size;
    string S;
    getline(cin, S);
    
    for (int row = 0; row < size; row++)
    {
        string S;
        getline(cin, S);
        for (int col = 0; col < size; col++)
        {
            matrix[row][col] = S[col];
            if (matrix[row][col] == '@')
            {
                start.row = row;
                start.col = col;
            }
            if (matrix[row][col] == 'X')
            {
                finish.row = row;
                finish.col = col;
            }
        }
    }
}

bool over_border(cord cor, int size)
{
    return (cor.row == -1 || cor.row == size || cor.col == -1 || cor.col == size);
}

void process_cell(cord cur_cord, char matrix[][50], char letter, cord queue[], int q_len, int &add_len)
{
    if (matrix[cur_cord.row][cur_cord.col] == '.' || matrix[cur_cord.row][cur_cord.col] == 'X')
    {
        matrix[cur_cord.row][cur_cord.col] = letter;
        queue[add_len + q_len].row = cur_cord.row;
        queue[add_len + q_len].col = cur_cord.col;
        add_len++;
    }
}

bool find_route(char matrix[][50], int size, cord start, cord finish)
{
    cord queue[5000], cur_cord = start;
    int cur = 0, q_len = 1;
    queue[0] = start;
    
    while (q_len > cur)
    {
        int add_len = 0;
        
        for (; cur < q_len; cur++)
        {
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col + 1;
            
            if (not(over_border(cur_cord, size)))
                process_cell(cur_cord, matrix, 'p', queue, q_len, add_len);
            
            if (cur_cord.row == finish.row && cur_cord.col == finish.col)
                return true;
            
            cur_cord.row = queue[cur].row - 1;
            cur_cord.col = queue[cur].col;
            
            if (not(over_border(cur_cord, size)))
                process_cell(cur_cord, matrix, 'v', queue, q_len, add_len);
            
            if (cur_cord.row == finish.row && cur_cord.col == finish.col)
                return true;
            
            cur_cord.row = queue[cur].row + 1;
            cur_cord.col = queue[cur].col;
            
            if (not(over_border(cur_cord, size)))
                process_cell(cur_cord, matrix, 'n', queue, q_len, add_len);
            
            if (cur_cord.row == finish.row && cur_cord.col == finish.col)
                return true;
            
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col - 1;
            
            if (not(over_border(cur_cord, size)))
                process_cell(cur_cord, matrix, 'l', queue, q_len, add_len);
            
            if (cur_cord.row == finish.row && cur_cord.col == finish.col)
                return true;
        }
        q_len += add_len;
    }
    
    return false;
}

void fix_matrix(int size, char matrix[][50])
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (matrix[row][col] != 'O' && matrix[row][col] != '+' && matrix[row][col] != '@') matrix[row][col] = '.';
        }
    }
}

void mark_route(int size, char matrix[][50], cord start, cord finish)
{
    int row = finish.row, col = finish.col;
    
    while(row != start.row || col != start.col)
    {
        if (matrix[row][col] == 'l')
        {
            matrix[row][col] = '+';
            col++;
        }
        else if (matrix[row][col] == 'p')
        {
            matrix[row][col] = '+';
            col--;
        }
        else if (matrix[row][col] == 'v')
        {
            matrix[row][col] = '+';
            row++;
        }
        else if (matrix[row][col] == 'n')
        {
            matrix[row][col] = '+';
            row--;
        }
    }
    
    fix_matrix(size, matrix);
}

void print_matrix(int size, char matrix[][50])
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
            cout << matrix[row][col];
        cout << '\n';
    }
}

int main()
{
    char matrix[50][50];
    int size;
    cord start, finish;
    
    read_matrix(size, matrix, start, finish);
    if (not(find_route(matrix, size, start, finish))) cout << 'N';
    else
    {
        mark_route(size, matrix, start, finish);
        cout << 'Y' << '\n';
        print_matrix(size, matrix);
    }
}
