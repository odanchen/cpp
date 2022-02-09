#include<iostream>
#include<fstream>

using namespace::std;

void fill_arr(int arr[], bool &status, ifstream& file)
{
    status = false;
    string S;
    while(getline(file, S))
    {
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
    ifstream input("analiz.in");
    ofstream output("analiz.out");
    int letters[128] = {0};
    bool status;
    
    fill_arr(letters, status, input);
    input.close();
    
    if (status)
    {
        for(char i = 'A'; i <= 'Z'; i++)
        {
            output << i << ' ' << letters[i] << '\n';
        }
    }
    else
        output << -1;
    output.close();
}
