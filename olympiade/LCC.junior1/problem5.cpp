#include <iostream>
#include <vector>

using namespace::std;

void readArr(vector<int> &arr, int len)
{
    arr.resize(len);
    for (int i = 0; i < len; i++) cin >> arr[i];
}

void trim(vector<int> &candies, vector<int> &aaron)
{
    while(candies.empty() == false && aaron.empty() == false && candies.back() == aaron.back())
    {
        candies.pop_back();
        aaron.pop_back();
    }
    
    while (candies.empty() == false && aaron.empty() == false && candies.front() == aaron.front())
    {
        candies.erase(candies.begin());
        aaron.erase(aaron.begin());
    }
}

int findPair(vector<int> &arr)
{
    if (arr.empty()) return -1;
    
    for(int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1]) return i;
    }
    
    return -1;
}

void mergePair(vector<int> &arr, int pair)
{
    arr[pair]++;
    arr.erase(arr.begin() + pair + 1);
}

bool areIdentical(vector<int> &candies, vector<int> &aaron)
{
    if (candies.back() != aaron.back()) return false;
    
    trim(candies, aaron);
    
    while(findPair(candies) != -1)
    {
        trim(candies, aaron);
        int pair = findPair(candies);
        if (pair != -1) mergePair(candies, pair);
        trim(candies, aaron);
    }
    
    return candies.empty() && aaron.empty();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int streets;
    cin >> streets;
    
    for(int i = 0; i < streets; i++)
    {
        int houses, aaronCnt;
        cin >> houses >> aaronCnt;
        vector<int> candies, aaronCandies;
        
        readArr(candies, houses);
        readArr(aaronCandies, aaronCnt);
        
        if (areIdentical(candies, aaronCandies)) cout << "VALID\n";
        else cout << "INVALID\n";
    }
}
