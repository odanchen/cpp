#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

struct cord
{
    double x;
    double y;
};

double sqr(double num)
{
    return num * num;
}

double distance(cord dot1, cord dot2)
{
    return sqrt(sqr(dot1.x - dot2.x) + sqr(dot1.y - dot2.y));
}

void read_arr(cord arr[], int &len)
{
    cin >> len;
    
    for (int i = 0; i < len; i++)
        cin >> arr[i].x >> arr[i].y;
}

void fill_ans_arr(int &ans_len, cord ans_arr[], cord arr[], int cnt)
{
    double max_len = 0;
    ans_len = 0;
    cord zero;
    zero.x = 0; zero.y = 0;
    
    for (int i = 0; i < cnt; i++)
    {
        if (max_len < distance(zero, arr[i]))
        {
            max_len = distance(zero, arr[i]);
            ans_arr[0] = arr[i];
            ans_len = 1;
        }
        else if(max_len == distance(zero, arr[i]))
        {
            ans_arr[ans_len] = arr[i];
            ans_len++;
        }
    }
}

void print_ans(cord arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i].x << ' ' << arr[i].y << '\n';
}

int main()
{
    cord arr[1000], ans_arr[1000];
    int len, ans_len;
    read_arr(arr, len);
    
    fill_ans_arr(ans_len, ans_arr, arr, len);
    print_ans(ans_arr, ans_len);
}
