#include <iostream>

using namespace std;

struct record
{
    int value;
    struct record *next;
    struct record *prev;
};

struct record *tail = NULL;

struct record *insert(struct record *head,int data)
{
    struct record *node = new struct record;
    node -> value = data;
    node -> next = NULL;
    node -> prev = NULL;

    if(head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail -> next = node;
        node -> prev = tail;
        tail = node;
    }
    return head;
}

int main()
{
    int n;
    struct record *head = NULL;
    cout << "Enter : ";
    cin >> n;
    head = insert(head,n);
    cout << "Print from head : ";
    cout << head -> value << endl;
    cout << "Print from tail : ";
    cout << tail -> value << endl;

    return 0;
}
