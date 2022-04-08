#include<iostream>

using namespace::std;

int res(int num)
{
    int nums[35];
    nums[0] = 2;
    nums[1] = 4;
    
    for (int i = 2; i < num; i++)
    {
        nums[i] = nums[i - 1] + nums[i - 2];
    }
    
    return nums[num - 1];
}

int main()
{
    int num;
    cin >> num;
    cout << res(num);
}
