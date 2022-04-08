#include<iostream>

using namespace::std;

void fill_fib_nums(int fib_nums[])
{
    fib_nums[0] = 1;
    fib_nums[1] = 1;
        
    for (int i = 2; i < 45; i++)
        fib_nums[i] = fib_nums[i - 1] + fib_nums[i - 2];
}

char k_symbol(int num, int pos)
{
    int fib_nums[45];
    fill_fib_nums(fib_nums);
    
    while(num > 1)
    {
        if (pos <= fib_nums[num - 2]) num -= 2;
        
        else
        {
            pos -= fib_nums[num - 2];
            num--;
        }
    }
    
    if (num == 1) return 'b';
    return 'a';
}

int main()
{
    int cnt, pos, len;
    cin >> cnt;
    
    for (int i = 0; i < cnt; i++)
    {
        cin >> len;
        cin >> pos;
        
        cout << k_symbol(len, pos) << '\n';
    }
}
