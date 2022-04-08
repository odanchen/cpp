#include<iostream>

using namespace::std;

struct cord
{
    int row;
    int col;
    int layer;
};

void read_cube(int &size, char matrix[][52][52], cord &start)
{
    cin >> size;
    string S;
    getline(cin, S);
    
    for (int layer = size - 1; layer >= 0; layer--)
    {
        getline(cin, S);
        
        for (int row = 0; row < size; row++)
        {
            string S;
            getline(cin, S);
            for (int col = 0; col < size; col++)
            {
                matrix[row][col][layer] = S[col];
                if (matrix[row][col][layer] == 'S')
                {
                    start.row = row;
                    start.col = col;
                    start.layer = layer;
                }
            }
        }
    }
}

bool over_border(cord cor, int size)
{
    return (cor.row == -1 || cor.row == size || cor.col == -1 || cor.col == size || cor.layer == -1);
}

void process_cell(cord cur_cord, char cube[][52][52], cord queue[], int q_len, int &add_len)
{
    if (cube[cur_cord.row][cur_cord.col][cur_cord.layer] == '.')
    {
        cube[cur_cord.row][cur_cord.col][cur_cord.layer] = 'V';
        queue[add_len + q_len].row = cur_cord.row;
        queue[add_len + q_len].col = cur_cord.col;
        queue[add_len + q_len].layer = cur_cord.layer;
        add_len++;
    }
}

int find_route(char cube[][52][52], int size, cord start)
{
    cord queue[100000], cur_cord = start;
    int cur = 0, q_len = 1;
    queue[0] = start;
    
    int cnt = 1;
    
    while (q_len > cur)
    {
        int add_len = 0;
        
        for (; cur < q_len; cur++)
        {
            cur_cord.row = queue[cur].row - 1;
            cur_cord.col = queue[cur].col;
            cur_cord.layer = queue[cur].layer;
            
            if (not(over_border(cur_cord, size)))
            {
                process_cell(cur_cord, cube, queue, q_len, add_len);
            
                if (cur_cord.layer == size - 1 && cube[cur_cord.row][cur_cord.col][cur_cord.layer] != '#')
                    return cnt;
            }
            
            
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col - 1;
            cur_cord.layer = queue[cur].layer;
            
            if (not(over_border(cur_cord, size)))
            {
                process_cell(cur_cord, cube, queue, q_len, add_len);
            
                if (cur_cord.layer == size - 1 && cube[cur_cord.row][cur_cord.col][cur_cord.layer] != '#')
                    return cnt;
            }
            
            
            cur_cord.row = queue[cur].row + 1;
            cur_cord.col = queue[cur].col;
            cur_cord.layer = queue[cur].layer;
            
            if (not(over_border(cur_cord, size)))
            {
                process_cell(cur_cord, cube, queue, q_len, add_len);
            
                if (cur_cord.layer == size - 1 && cube[cur_cord.row][cur_cord.col][cur_cord.layer] != '#')
                    return cnt;
            }
            
            
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col + 1;
            cur_cord.layer = queue[cur].layer;
            
            if (not(over_border(cur_cord, size)))
            {
                process_cell(cur_cord, cube, queue, q_len, add_len);
            
                if (cur_cord.layer == size - 1 && cube[cur_cord.row][cur_cord.col][cur_cord.layer] != '#')
                    return cnt;
            }
            
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col;
            cur_cord.layer = queue[cur].layer + 1;
            
            process_cell(cur_cord, cube, queue, q_len, add_len);
        
            if (cur_cord.layer == size - 1 && cube[cur_cord.row][cur_cord.col][cur_cord.layer] != '#')
                return cnt;
            
            
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col;
            cur_cord.layer = queue[cur].layer - 1;
            
            if (not(over_border(cur_cord, size)))
            {
                process_cell(cur_cord, cube, queue, q_len, add_len);
            
                if (cur_cord.layer == size - 1 && cube[cur_cord.row][cur_cord.col][cur_cord.layer] != '#')
                    return cnt;
            }

        }
        q_len += add_len;
        cnt++;
    }
    
    return cnt;
}

int main()
{
    char cube[52][52][52];
    int size;
    cord start;
    
    read_cube(size, cube, start);
    cout << find_route(cube, size, start);
}
