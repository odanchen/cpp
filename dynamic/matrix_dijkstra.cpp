#include<iostream>

using namespace::std;

const int border = 1000000000;

struct node
{
    int value = border;
    int path = border;
};

struct cord
{
    int row = 12;
    int col = 12;
};

int min_queue(cord queue[], int cnt, int q_len, node matrix[][12])
{
    int cur = border + 1, ans = 0;
    
    for (int i = cnt; i < q_len; i++)
    {
        if (matrix[queue[i].row][queue[i].col].path < cur)
        {
            cur = matrix[queue[i].row][queue[i].col].path;
            ans = i;
        }
    }
    
    return ans;
}

bool is_inside(cord cor, int heigth, int width)
{
    return (cor.row <= heigth && cor.row >= 1 && cor.col <= width && cor.col >= 1);
}

void add_queue(int minimum, cord next, node matrix[][12], cord queue[], int q_len, int &add_len)
{
    if  ((matrix[next.row][next.col].path - matrix[next.row][next.col].value) > minimum)
    {
        queue[q_len + add_len] = next;
        add_len++;
    }
}

void process_node(cord cur, node matrix[][12], cord queue[], int q_len, int &add_len)
{
    cord next;
    char direction = 'n';
    int row = cur.row; int col = cur.col;
    
    if (row == 1 && col == 1)
    {
        matrix[row][col].path = matrix[row][col].value;
        next.row = row + 1; next.col = col;
        queue[q_len + add_len] = next;
        add_len++;
        next.row = row; next.col = col + 1;
        queue[q_len + add_len] = next;
        add_len++;
    }
    else
    {
        int minimum = matrix[row + 1][col].path + matrix[row][col].value;
    
        if (minimum > matrix[row - 1][col].path + matrix[row][col].value)
        {
            minimum = matrix[row - 1][col].path + matrix[row][col].value;
            direction = 'v';
        }
        if (minimum > matrix[row][col - 1].path + matrix[row][col].value)
        {
            minimum = matrix[row][col - 1].path + matrix[row][col].value;
            direction = 'l';
        }
        if (minimum > matrix[row][col + 1].path + matrix[row][col].value)
        {
            minimum = matrix[row][col + 1].path + matrix[row][col].value;
            direction = 'p';
        }
    
        if (minimum < matrix[row][col].path)
        {
            if (direction == 'v')
            {
                next.row = row + 1; next.col = col;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
                next.row = row; next.col = col + 1;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
                next.row = row; next.col = col - 1;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
            }
            if (direction == 'n')
            {
                next.row = row - 1; next.col = col;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
                next.row = row; next.col = col + 1;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
                next.row = row; next.col = col - 1;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
            }
            if (direction == 'l')
            {
                next.row = row + 1; next.col = col;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
                next.row = row; next.col = col + 1;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
                next.row = row - 1; next.col = col;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
            }
            if (direction == 'p')
            {
                next.row = row + 1; next.col = col;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
                next.row = row; next.col = col - 1;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
                next.row = row - 1; next.col = col;
                add_queue(minimum, next, matrix, queue, q_len, add_len);
            }
            
            matrix[row][col].path = minimum;
        }
    }
}

void read_matrix(node matrix[][12], int &heigth, int &width)
{
    cin >> heigth >> width;
    
    for (int row = 1; row <= heigth; row++)
        for (int col = 1; col <= width; col++)
            cin >> matrix[row][col].value;
}

void fill_way(node matrix[][12], int heigth, int width)
{
    cord queue[300], cur_node;
    cur_node.row = 1;
    cur_node.col = 1;
    int q_len = 1, cnt = 0;
    queue[0] = cur_node;
        
    while (q_len > cnt)
    {
        int add_len = 0;
        int idx = min_queue(queue, cnt, q_len, matrix);
        cord cur;
        cur.row = queue[idx].row;
        cur.col = queue[idx].col;
        
        if (is_inside(cur, heigth, width))
            process_node(cur, matrix, queue, q_len, add_len);
        swap(queue[idx], queue[cnt]);
        cnt++;
        
        q_len += add_len;
    }
}

int main()
{
    node matrix[12][12];
    int heigth, width;
    
    read_matrix(matrix, heigth, width);
    fill_way(matrix, heigth, width);
    
    cout << matrix[heigth][width].path;
}
