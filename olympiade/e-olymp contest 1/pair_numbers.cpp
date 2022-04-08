#include<iostream>

using namespace::std;

void fill_matrix(int left, int right, long long digits[][10])
{
    int grade = 1;
    while(left >= grade * 10)
        grade *= 10;
    for (int i = left; i <= right; i++)
    {
        if (i >= grade * 10)
            grade *= 10;
        digits[i / grade][i % 10]++;
    }
}

long long count_pairs(long long digits[][10])
{
    long long sum = 0;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            sum += digits[i][j] * digits[j][i];
        }
    }
    return sum;
}

int main()
{
    int left, right;
    long long digits[10][10] = {0};
    cin >> left >> right;
    fill_matrix(left, right, digits);
    cout << count_pairs(digits);
    return 0;
}
