#include <iostream>

using namespace::std;

long long countPairs(long long n)
{
    if (n == 1) return 0;
    else if (n == 2) return 1;
    
    return (n + (n * (n - 3) / 2));
}

long long countSpookyPairs(long long song[][4], long long left, long long right)
{
    long long ans = 0;
    
    ans += countPairs(song[right][0] - song[left - 1][0]);
    ans += countPairs(song[right][1] - song[left - 1][1]);
    ans += countPairs(song[right][2] - song[left - 1][2]);
    ans += countPairs(song[right][3] - song[left - 1][3]);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long songLen, sampleCnt;
    cin >> songLen >> sampleCnt;
    long long song[songLen + 1][4];
    
    for (int i = 0; i < 4; i++) song[0][i] = 0;
    
    for (int i = 1; i <= songLen; i++)
    {
        long long note;
        cin >> note;
        
        song[i][note % 4] = song[i - 1][note % 4] + 1;
        song[i][((note % 4) + 1) % 4] = song[i - 1][((note % 4) + 1) % 4];
        song[i][((note % 4) + 2) % 4] = song[i - 1][((note % 4) + 2) % 4];
        song[i][((note % 4) + 3) % 4] = song[i - 1][((note % 4) + 3) % 4];
    }
    
    for(int i = 0; i < sampleCnt; i++)
    {
        long long left, right;
        cin >> left >> right;
        
        cout << countSpookyPairs(song, left, right) << '\n';
    }
}
