#include<iostream>
#include<iomanip>
#include<cmath>

using namespace::std;

char get_operation(string S, string operations)
{
    return S[S.find_first_of(operations, 1)];
}

string get_num_1(string S, string operations)
{
    int last_idx = (int)S.find_first_of(operations, 1);
    
    return S.substr(0, last_idx);
    
}

string get_num_2(string S, string operations)
{
    int first_idx = (int)S.find_first_of(operations, 1);
    
    return S.substr(first_idx + 1);
    
}

double operation_res(double num1, double num2, char operation)
{
    if (operation == '+') return num1 + num2;
    if (operation == '-') return num1 - num2;
    if (operation == '*') return num1 * num2;
    return num1 / num2;
}

int main()
{
    freopen("expression_1.in", "r", stdin);
    freopen("expression_1.out", "w", stdout);
    
    string operations = "+-*/";
    string S;
    
    while(getline(cin, S))
    {
        double num1 = stod(get_num_1(S, operations));
        double num2 = stod(get_num_2(S, operations));
        char operation = get_operation(S, operations);
        double res = operation_res(num1, num2, operation);
        
        if (num2 == 0 && operation == '/')
            cout << "Error" << '\n';
        else if (trunc(res) == res)
            cout << fixed << setprecision(0) << res << '\n';
        else
            cout << fixed << setprecision(4) << res << '\n';
    }
}
