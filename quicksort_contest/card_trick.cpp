#include <bits/stdc++.h>
using namespace std;

void read_arr(int arr[], int &length)
{
    int num;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> num;
        arr[num]++;
    }
}

void null_arr(int arr[])
{
    for (int i = 0; i < 57; i++)
        arr[i] = 0;
}

bool is_enough_cards(int cards[], int deck[], int length)
{
    for (int i = 0; i < 57; i++)
        if (deck[i] < cards[i]) return false;
    return true;
}

void print_results(int cards[], int deck[], int length, int &decks)
{
    cin >> decks;
    for (int i = 0; i < decks; i++)
    {
        null_arr(deck);
        read_arr(deck, length);
        if (is_enough_cards(cards, deck, length)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int deck[57] = {}, cards[57] = {}, length, decks;
    read_arr(cards, length);
    print_results(cards, deck, length, decks);
    return 0;
}
