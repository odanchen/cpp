#include<iostream>

using namespace::std;

struct cord
{
    int row;
    int col;
};

void read_matrix(char matrix[][100], int &heigth, int &width)
{
    cin >> heigth >> width;
    
    for (int row = 0; row < heigth; row++)
        for (int col = 0; col < width; col++)
            cin >> matrix[row][col];
}

bool over_border(cord cor, int heigth, int width)
{
    return (cor.row == -1 || cor.row == heigth || cor.col == -1 || cor.col == width);
}

void process_cell(cord cur_cord, char matrix[][100], cord queue[], int q_len, int &add_len)
{
    if (matrix[cur_cord.row][cur_cord.col] == '#')
    {
        matrix[cur_cord.row][cur_cord.col] = '0';
        queue[add_len + q_len].row = cur_cord.row;
        queue[add_len + q_len].col = cur_cord.col;
        add_len++;
    }
}

void mark_piece(char matrix[][100], int heigth, int width, cord start)
{
    cord queue[10000], cur_cord = start;
    int cur = 0, q_len = 1;
    queue[0] = start;
    
    while (q_len > cur)
    {
        int add_len = 0;
        
        for (; cur < q_len; cur++)
        {
            cur_cord.row = queue[cur].row - 1;
            cur_cord.col = queue[cur].col;
            if (not(over_border(cur_cord, heigth, width)))
                process_cell(cur_cord, matrix, queue, q_len, add_len);
            
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col - 1;
            if (not(over_border(cur_cord, heigth, width)))
                process_cell(cur_cord, matrix, queue, q_len, add_len);
            
            cur_cord.row = queue[cur].row + 1;
            cur_cord.col = queue[cur].col;
            if (not(over_border(cur_cord, heigth, width)))
                process_cell(cur_cord, matrix, queue, q_len, add_len);
            
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col + 1;
            if (not(over_border(cur_cord, heigth, width)))
                process_cell(cur_cord, matrix, queue, q_len, add_len);
        }
        q_len += add_len;
    }
}

int count_pieces(char matrix[][100], int heigth, int width)
{
    int cnt = 0;
    cord cor;
    
    for (int row = 0; row < heigth; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (matrix[row][col] == '#')
            {
                cor.row = row; cor.col = col;
                mark_piece(matrix, heigth, width, cor);
                cnt++;
            }
        }
    }
    
    return cnt;
}

int main()
{
    int heigth, width;
    char matrix[100][100];
    
    read_matrix(matrix, heigth, width);
    cout << count_pieces(matrix, heigth, width);
}
