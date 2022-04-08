#include<iostream>

using namespace::std;

struct cord
{
    int row;
    int col;
};

void read_matrix(int &heigth, int &width, char matrix[][3000], cord &start)
{
    cin >> heigth >> width;
    string S;
    getline(cin, S);
    
    for (int row = 0; row < heigth; row++)
    {
        string S;
        getline(cin, S);
        for (int col = 0; col < width; col++)
        {
            matrix[row][col] = S[col];
            if (matrix[row][col] == '+')
            {
                start.row = row;
                start.col = col;
            }
        }
    }
}

bool on_border(cord cor, int heigth, int width)
{
    return (cor.row == 0 || cor.row == heigth -1 || cor.col == 0 || cor.col == width -1);
}

void process_cell(cord cur_cord, char matrix[][3000], char letter, cord queue[], int q_len, int &add_len)
{
    if (matrix[cur_cord.row][cur_cord.col] == ' ')
    {
        matrix[cur_cord.row][cur_cord.col] = letter;
        queue[add_len + q_len].row = cur_cord.row;
        queue[add_len + q_len].col = cur_cord.col;
        add_len++;
    }
}

cord find_route(char matrix[][3000], int heigth, int width, cord start, int &cnt)
{
    cord queue[300000], cur_cord = start;
    int cur = 0, q_len = 1;
    queue[0] = start;
    
    cnt = 0;
    
    while (q_len > cur)
    {
        int add_len = 0;
        
        for (; cur < q_len; cur++)
        {
            cur_cord.row = queue[cur].row - 1;
            cur_cord.col = queue[cur].col;
            
            process_cell(cur_cord, matrix, 'n', queue, q_len, add_len);
            
            if (on_border(cur_cord, heigth, width) && matrix[cur_cord.row][cur_cord.col] == 'w')
                return cur_cord;
            
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col - 1;
            
            process_cell(cur_cord, matrix, 'w', queue, q_len, add_len);
            
            if (on_border(cur_cord, heigth, width) && matrix[cur_cord.row][cur_cord.col] == 'w')
                return cur_cord;
            
            cur_cord.row = queue[cur].row + 1;
            cur_cord.col = queue[cur].col;
            
            process_cell(cur_cord, matrix, 's', queue, q_len, add_len);
            
            if (on_border(cur_cord, heigth, width) && matrix[cur_cord.row][cur_cord.col] == 's')
                return cur_cord;
            
            cur_cord.row = queue[cur].row;
            cur_cord.col = queue[cur].col + 1;
            
            process_cell(cur_cord, matrix, 'e', queue, q_len, add_len);
            
            if (on_border(cur_cord, heigth, width) && matrix[cur_cord.row][cur_cord.col] == 'e')
                return cur_cord;
        }
        q_len += add_len;
        cnt++;
    }
    
    return start;
}

string mark_route(char matrix[][3000], cord finish)
{
    cord cur_cord = finish;
    string ans = "";
    
    while(matrix[cur_cord.row][cur_cord.col] != '+')
    {
        if (matrix[cur_cord.row][cur_cord.col] == 'w')
        {
            ans += "w";
            cur_cord.col++;
        }
        
        if (matrix[cur_cord.row][cur_cord.col] == 'e')
        {
            ans += "e";
            cur_cord.col--;
        }
        
        if (matrix[cur_cord.row][cur_cord.col] == 's')
        {
            ans += "s";
            cur_cord.row--;
        }
        
        if (matrix[cur_cord.row][cur_cord.col] == 'n')
        {
            ans += "n";
            cur_cord.row++;
        }
    }
    
    for (int i = 0; i < ans.size()/2; i++)
    {
        swap(ans[i], ans[ans.size() - 1 - i]);
    }
    return ans;
}

int main()
{
    char matrix[3000][3000];
    int heigth, width, cnt;
    cord start, finish;
    
    read_matrix(heigth, width, matrix, start);
    
    if (on_border(start, heigth, width)) cout << 0;
    else
    {
        finish = find_route(matrix, heigth, width, start, cnt);
        if (finish.row == start.row && finish.col == start.col) cout << -1;
        
        else
        {
            string ans;
            cout << cnt + 1 << '\n';
            ans = mark_route(matrix, finish);
            cout << ans;
        }
    }
}
