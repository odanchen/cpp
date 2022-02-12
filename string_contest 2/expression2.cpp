#include<iostream>
#include<iomanip>
#include<cmath>

using namespace::std;

const long long type_max = 9223372036854775807;

string find_word(string S, int &start_idx, string separators)
{
    int start = S.find_first_not_of(separators, start_idx);
    int finish = S.find_first_of(separators, start);
    
    if (start == -1) start_idx = -1;
    else start_idx = finish;
    
    if (start != 0) start -= 1;
    
    if (start == -1 || start > S.size()) return "";
    if (finish == -1 || finish > S.size()) return S.substr(start);
    
    return S.substr(start, finish - start);
}

void swap_sign(char &sign)
{
    if (sign == '+') sign = '-';
    else sign = '+';
}

int main()
{
    freopen("expression_2.in", "r", stdin);
    freopen("expression_2.out", "w", stdout);
    
    string operations = "+-*/";
    string S;
    
    while(getline(cin, S))
    {
        if (S.empty()) cout << "NULL" << '\n';
        else
        {
            int start_idx = 0;
            char sign = '+';
            unsigned long long sum = 0;
            
            while(start_idx != -1 && sum < type_max)
            {
                long long add = stoll(find_word(S, start_idx, operations));
                char asign = '+';
                if (add < 0){
                    asign = '-';
                    add = abs(add);
                }
                else asign = '+';
                
                if (sign == asign) sum += add;
                else if(sum < add)
                {
                    sum = add - sum;
                    swap_sign(sign);
                }
                else sum -= add;
            }
            
            if (sum > type_max) cout << "Error" << '\n';
            else if (sign == '+') cout << sum << '\n';
            else cout << sign << sum << '\n';
        }
    }
}
