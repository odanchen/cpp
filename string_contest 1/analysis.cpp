#include<iostream>
#include<fstream>

using namespace::std;

void fill_arr(int arr[], bool &status, ofstream file)
{
    status = false;
    string S;
    while(!file.eof())
    {
        getline(cin, S);
        for (int i = 0; i < S.size(); i++)
            if (isalpha(S[i]))
            {
                arr[toupper(S[i])]++;
                status = true;
            }
    }
}

int main()
{
    ofstream file;
    file.open("analiz.in");
    int letters[128];
    bool status;
    fill_arr(letters, status, file);
    if (status == true)
    {
        for(char i = 'A'; i <= 'Z'; i++)
        {
            cout << i << ' ' << letters[i] << '\n';
        }
    }
    else
        cout << -1;
}
