#include<iostream>

using namespace::std;

bool is_leap(int year)
{
    if (year % 400 == 0)
        return true;
 
    if (year % 100 == 0)
        return false;
 
    if (year % 4 == 0)
        return true;
    return false;
}

void get_date(string S, int &year, int &month, int &date)
{
    date = (S[S.size() - 1] - '0') * 10 + (S[S.size() - 2] - '0');
    month = (S[S.size() - 3] - '0') * 10 + (S[S.size() - 4] - '0');
    year = (S[S.size() - 6] - '0') * 1000 + (S[S.size() - 7] - '0') * 100
    + (S[S.size() - 9] - '0') * 10 + (S[S.size() - 10] - '0');
}

int  days_num(int month, int year)
{
    if(month == 2)
    {
        if(is_leap(year))
            return 29;
        else
            return 28;
    }
    
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
    || month == 10 || month==12)
        return 31;
    else
        return 30;
}

bool is_valid(string S)
{
    int year, month, date;
    get_date(S, year, month, date);
    
    if (month > 12) return false;
    
    return date <= days_num(month, year);
}

int main()
{
    string S;
    int repeats;
    cin >> repeats;
    
    for (int i = 0; i < repeats; i++)
    {
        cin >> S;
        if (is_valid(S))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}
