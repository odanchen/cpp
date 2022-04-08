#include<iostream>
#include<vector>

using namespace::std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    vector<int> ways = {0};
    ways.resize(n + 1);
    
    ways[0] = 1;
    for (int i = 0; i < denoms.size(); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(j - denoms[i] >= 0) ways[j] += ways[j - denoms[i]];
        }
    }
    
    return ways[n];
}
