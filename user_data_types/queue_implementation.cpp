#include<iostream>

using namespace::std;

struct Queue
{
    Queue *left = NULL;
    Queue *right= NULL;
    int value;
};

void push(Queue *&head, Queue *&tail, int value)
{
    Queue *temporary_top = new Queue;
    
    if(head == NULL)
    {
        temporary_top->value = value;
        tail = temporary_top;
    }
    else
    {
        temporary_top->value = value;
        temporary_top->left = head;
        head->right = temporary_top;
    }
    head = temporary_top;
}

bool isEmpty(Queue *tail)
{
    return (tail == NULL);
}

void pop(Queue *&head, Queue *&tail)
{
    if (tail == head)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        Queue *temporary_bottom = tail;
        tail = tail->right;
        delete temporary_bottom;
    }
}

int front(Queue *&tail)
{
    return tail->value;
}

void clear(Queue *&head, Queue *&tail)
{
    while (head != tail)
    {
        Queue *temporary_top = head;
        head = head->left;
        delete temporary_top;
    }
    head = NULL;
    tail = NULL;
}

int size(Queue *&head, Queue *&tail)
{
    if (tail == NULL || head == NULL) return 0;
    
    int cnt = 0;
    Queue *temp = tail;
    while(temp != head)
    {
        temp = temp->right;
        cnt++;
    }
    return cnt + 1;
}

int main()
{
    Queue *head = NULL, *tail = NULL;
    string command = "";
    int value;
    
    while (command != "exit")
    {
        cin >> command;
        
        if (command == "push")
        {
            cin >> value;
            push(head, tail, value);
            cout << "ok" << '\n';
        }
        
        else if (command == "pop")
        {
            if (isEmpty(tail)) cout << "error" << '\n';
            else
            {
                cout << front(tail) << '\n';
                pop(head, tail);
            }
        }
        
        else if (command == "front")
        {
            if (isEmpty(tail)) cout << "error" << '\n';
            else
            {
                cout << front(tail) << '\n';
            }
        }
        
        else if (command == "clear")
        {
            clear(head, tail);
            cout << "ok" << '\n';
        }
        
        else if (command == "size")
        {
            cout << size(head, tail) << '\n';
        }
    }
    cout << "bye";
}
