
#include<iostream>

using namespace::std;

struct Stack
{
    Stack *prev = NULL;
    int value;
    int size = 0;
};

void push(Stack *&top, int value)
{
    Stack *temporary_top = new Stack;
    
    temporary_top->value = value;
    temporary_top->prev = top;
    
    if (temporary_top->prev == NULL)temporary_top->size = 1;
    else temporary_top->size = temporary_top->prev->size + 1;
    
    top = temporary_top;
}

bool isEmpty(Stack *&top)
{
    return (top == NULL);
}

void pop(Stack *&top)
{
    if (top->prev == NULL)
    {
        top = NULL;
        return;
    }
    
    Stack *temporary_top = top;
    top = top->prev;
    delete temporary_top;
}

int back(Stack *&top)
{
    return top->value;
}

void clear(Stack *&top)
{
    while (top != NULL)
    {
        Stack *temporary_top = new Stack;
        temporary_top = top;
        top = top->prev;
        delete temporary_top;
    }
    delete top;
}

int size(Stack *&top)
{
    if (top == NULL) return 0;
    return top->size;
}

int main()
{
    Stack *performer = NULL;
    string command = "";
    int value;
    
    while (command != "exit")
    {
        cin >> command;
        
        if (command == "push")
        {
            cin >> value;
            push(performer, value);
            cout << "ok" << '\n';
        }
        
        else if (command == "pop")
        {
            if (isEmpty(performer)) cout << "error" << '\n';
            else
            {
                cout << back(performer) << '\n';
                pop(performer);
            }
        }
        
        else if (command == "back")
        {
            if (isEmpty(performer)) cout << "error" << '\n';
            else cout << back(performer) << '\n';
        }
        
        else if (command == "clear")
        {
            clear(performer);
            cout << "ok" << '\n';
        }
        
        else if (command == "size") cout << size(performer) << '\n';
    }
    cout << "bye";
}
