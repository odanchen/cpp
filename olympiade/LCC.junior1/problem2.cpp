#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int candies[26] = {0};
    int candiesNum, friendsNum;
    
    cin >> candiesNum >> friendsNum;
    
    for (int i = 0; i < candiesNum; i++)
    {
        char candy;
        cin >> candy;
        candies[candy - 'a']++;
    }
    
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += candies[i] / friendsNum;
    }
    
    cout << ans;
}
