#include<iostream>

using namespace::std;

bool is_correct(string S)
{
    bool inside = false;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '(' && inside == true) return false;
        else if (S[i] == ')' && inside == false) return false;
        inside = not(inside);
    }
    return true;
}

int main()
{
    string notes;
    getline(cin, notes);
    if (is_correct(notes))
    {
        if(notes[notes.size() - 1] == '(') cout << "INSIDE";
        else cout << "OUTSIDE";
    }
    else cout << "ERROR";
}
