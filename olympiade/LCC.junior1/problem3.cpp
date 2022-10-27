#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int scores[200000] = {0};
    int contestants, friends;
    
    cin >> contestants >> friends;
    
    for (int i = 0; i < contestants; i++)
    {
        int score;
        cin >> score;
        scores[score]--;
    }
    
    int rank = 1;
    
    for (int i = 200000 - 1; i >= 0 ; i--)
    {
        if(scores[i] < 0)
        {
            int temp = rank;
            rank += abs(scores[i]);
            scores[i] = temp;
        }
    }
    
    for (int i = 0; i < friends; i++)
    {
        int friendScore;
        cin >> friendScore;
        cout << scores[friendScore] << '\n';
    }
}
