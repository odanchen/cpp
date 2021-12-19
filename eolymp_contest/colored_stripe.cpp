#include<iostream>

using namespace::std;

void read_arr(char arr[], int &len)
{
    len = 0;
    while (cin.peek() != '\n')
        cin >> arr[len++];
}

int count_pieces(char arr[], int len)
{
    int counter = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if ((arr[i] == 'R' && arr[i + 1] == 'B') || (arr[i] == 'B' && arr[i + 1] == 'R'))
        {
            counter++;
            i++;
        }
    }
    return counter;
}

int main()
{
    char tape[100000];
    int len;
    read_arr(tape, len);
    cout << count_pieces(tape, len);
    return 0;
}
