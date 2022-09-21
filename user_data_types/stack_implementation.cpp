#include<iostream>

using namespace::std;

struct Stack
{
    Stack *prev = NULL;
    int value;
    int size = 0;
};

void push(Stack *&head, int value)
{
    Stack *temporary_top = new Stack;
    
    temporary_top->value = value;
    temporary_top->prev = head;
    
    if (temporary_top->prev == NULL)temporary_top->size = 1;
    else temporary_top->size = temporary_top->prev->size + 1;
    
    head = temporary_top;
}

bool isEmpty(Stack *&head)
{
    return (head == NULL);
}

void pop(Stack *&head)
{
    if (head->prev == NULL)
    {
        head = NULL;
        return;
    }
    
    Stack *temporary_top = head;
    head = head->prev;
    delete temporary_top;
}

int back(Stack *&head)
{
    return head->value;
}

void clear(Stack *&head)
{
    while (head != NULL)
    {
        Stack *temporary_top = new Stack;
        temporary_top = head;
        head = head->prev;
        delete temporary_top;
    }
    delete head;
}

int size(Stack *&head)
{
    if (head == NULL) return 0;
    return head->size;
}

int main()
{
    Stack *head = NULL;
    string command = "";
    int value;
    
    while (command != "exit")
    {
        cin >> command;
        
        if (command == "push")
        {
            cin >> value;
            push(head, value);
            cout << "ok" << '\n';
        }
        
        else if (command == "pop")
        {
            if (isEmpty(head)) cout << "error" << '\n';
            else
            {
                cout << back(head) << '\n';
                pop(head);
            }
        }
        
        else if (command == "back")
        {
            if (isEmpty(head)) cout << "error" << '\n';
            else cout << back(head) << '\n';
        }
        
        else if (command == "clear")
        {
            clear(head);
            cout << "ok" << '\n';
        }
        
        else if (command == "size") cout << size(head) << '\n';
    }
    cout << "bye";
}
