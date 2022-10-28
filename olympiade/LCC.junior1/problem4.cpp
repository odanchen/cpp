#include <iostream>

using namespace::std;

long long countPairs(long long n)
{
    if (n == 1) return 0;
    else if (n == 2) return 1;
    
    return (n + (n * (n - 3) / 2));
}

long long countSpookyPairs(long long song0[], long long song1[], long long song2[], long long song3[], long long left, long long right)
{
    long long ans = 0;
    
    ans += countPairs(song0[right] - song0[left - 1]);
    ans += countPairs(song1[right] - song1[left - 1]);
    ans += countPairs(song2[right] - song2[left - 1]);
    ans += countPairs(song3[right] - song3[left - 1]);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long songLen, sampleCnt;
    cin >> songLen >> sampleCnt;
    long long song0[songLen + 1], song1[songLen + 1], song2[songLen + 1], song3[songLen + 1];
    
    for (int i = 1; i <= songLen; i++)
    {
        long long note;
        cin >> note;
        note = note % 4;
        song1[0] = 0;
        song2[0] = 0;
        song3[0] = 0;
        song0[0] = 0;
    
        if (note == 0)
        {
            song1[i] = song1[i - 1];
            song2[i] = song2[i - 1];
            song3[i] = song3[i - 1];
            song0[i] = song0[i - 1] + 1;
        }
        if (note == 1)
        {
            song1[i] = song1[i - 1] + 1;
            song2[i] = song2[i - 1];
            song3[i] = song3[i - 1];
            song0[i] = song0[i - 1];
        }
        if (note == 2)
        {
            song1[i] = song1[i - 1];
            song2[i] = song2[i - 1] + 1;
            song3[i] = song3[i - 1];
            song0[i] = song0[i - 1];
        }
        if (note == 3)
        {
            song1[i] = song1[i - 1];
            song2[i] = song2[i - 1];
            song3[i] = song3[i - 1] + 1;
            song0[i] = song0[i - 1];
        }
        
    }
    
    for(int i = 0; i < sampleCnt; i++)
    {
        long long left, right;
        cin >> left >> right;
        
        cout << countSpookyPairs(song0, song1, song2, song3, left, right) << '\n';
    }
}
