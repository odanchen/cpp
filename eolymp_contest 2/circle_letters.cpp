#include<iostream>

using namespace::std;

void read_arr(int &len, char arr[])
{
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
}

char minimal(int len, char arr[])
{
    char minimum = arr[0];
    for (int i = 0; i < len; i++)
        minimum = min(minimum, arr[i]);
    return minimum;
}

void rotate(char arr[], int len)
{
    for(int i = len; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = arr[len];
}

void print_arr(int len, char arr[])
{
    for (int i = 0; i < len; i++)
        cout << arr[i];
}

int count_substring(int len, char arr[])
{
    int substring = 0;
    for (int i = 0; i < len; i += 0)
    {
        int cur = 0;
        char prev = arr[i] - 1;
        while(arr[i] == prev + 1 && i < len)
        {
            cur++;
            i++;
            prev = arr[i - 1];
        }
        substring = max(substring, cur);
    }
    return substring;
}

int main()
{
    int len;
    char arr[10000], first;
    read_arr(len, arr);
    first = minimal(len, arr);
    while(arr[0] != first)
        rotate(arr, len);
    cout << count_substring(len, arr);
}
