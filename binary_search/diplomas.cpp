#include<iostream>
#include<cmath>

using namespace::std;

bool is_valid_side(long long side, long long heigth, long long width, long long cnt)
{
    return ((side / heigth) * (side / width) >= cnt);
}

long long find_square_side(long long heigth, long long width, long long cnt)
{
    long long left, right, mid;
    left = floor(sqrt(heigth) * sqrt(width) * sqrt(cnt));
    right = max(heigth, width) * cnt;
    mid = (left + right) / 2;
    
    while(left < right)
    {
        mid = floor(left + right) / 2;
        
        if (is_valid_side(left, heigth, width, cnt)) return left;
        
        if (is_valid_side(mid, heigth, width, cnt)) right = mid;
        else left = mid + 1;
    }
    
    return left;
}

int main()
{
    long long heigth, width, cnt;
    cin >> width >> heigth >> cnt;
    cout << find_square_side(heigth, width, cnt);
}
