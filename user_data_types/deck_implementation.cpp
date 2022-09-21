#include<iostream>

using namespace::std;

struct Deck
{
    Deck *left = NULL;
    Deck *right= NULL;
    int value;
};

void push_front(Deck *&head, Deck *&tail, int value)
{
    Deck *temporary_head = new Deck;
    
    if(head == NULL)
    {
        temporary_head->value = value;
        tail = temporary_head;
    }
    else
    {
        temporary_head->value = value;
        temporary_head->left = head;
        head->right = temporary_head;
    }
    head = temporary_head;
}

void push_back(Deck *&head, Deck *&tail, int value)
{
    Deck *temporary_tail = new Deck;
    
    if(tail == NULL)
    {
        temporary_tail->value = value;
        head = temporary_tail;
    }
    
    else
    {
        temporary_tail->value = value;
        temporary_tail->right = tail;
        tail->left = temporary_tail;
    }
    tail = temporary_tail;
}

bool isEmpty(Deck *tail)
{
    return (tail == NULL);
}

void pop_back(Deck *&head, Deck *&tail)
{
    if (tail == head)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        Deck *temporary_tail = tail;
        tail = tail->right;
        delete temporary_tail;
    }
}

void pop_front(Deck *&head, Deck *&tail)
{
    if (tail == head)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        Deck *temporary_top = head;
        head = head->left;
        delete temporary_top;
    }
}


int front(Deck *&head)
{
    return head->value;
}

int back(Deck *&tail)
{
    return tail->value;
}

void clear(Deck *&head, Deck *&tail)
{
    while (head != tail)
    {
        Deck *temporary_top = head;
        head = head->left;
        delete temporary_top;
    }
    head = NULL;
    tail = NULL;
}

int size(Deck *&head, Deck *&tail)
{
    if (tail == NULL || head == NULL) return 0;
    
    int cnt = 0;
    Deck *temp = tail;
    while(temp != head)
    {
        temp = temp->right;
        cnt++;
    }
    return cnt + 1;
}

int main()
{
    Deck *head = NULL, *tail = NULL;
    string command = "";
    int value;
    
    while (command != "exit")
    {
        cin >> command;
        
        if (command == "push_front")
        {
            cin >> value;
            push_front(head, tail, value);
            cout << "ok" << '\n';
        }
        
        else if (command == "push_back")
        {
            cin >> value;
            push_back(head, tail, value);
            cout << "ok" << '\n';
        }
        
        else if (command == "pop_front")
        {
            if (isEmpty(tail)) cout << "error" << '\n';
            else
            {
                cout << front(head) << '\n';
                pop_front(head, tail);
            }
        }
        
        else if (command == "pop_back")
        {
            if (isEmpty(tail)) cout << "error" << '\n';
            else
            {
                cout << back(tail) << '\n';
                pop_back(head, tail);
            }
        }
        
        else if (command == "front")
        {
            if (isEmpty(tail)) cout << "error" << '\n';
            else
            {
                cout << front(head) << '\n';
            }
        }
        
        else if (command == "back")
        {
            if (isEmpty(tail)) cout << "error" << '\n';
            else
            {
                cout << back(tail) << '\n';
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
    cout << "bye" << '\n';
}
