#include<iostream>

using namespace::std;

long long find_num(int border)
{
    long long i = 1, j = 1, current_num;
    int counter = 0;
    while(counter < border)
    {
        if (i * i > j * j * j)
        {
            current_num = j * j * j;
            j++;
            counter++;
        }
        else if (i * i < j * j * j)
        {
            current_num = i * i;
            i++;
            counter++;
        }
        else
        {
            current_num = i * i;
            i++;
            j++;
            counter++;
        }
    }
    return current_num;
}

int main()
{
    int border;
    cin >> border;
    cout << find_num(border);
}
