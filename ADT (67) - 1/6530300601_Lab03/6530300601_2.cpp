#include <iostream>

using namespace std;

struct record
{
    char c;
    struct record *next;
};

struct record *insertCode(struct record *head,char code[])
{
    int i = 0;
    struct record *temp = NULL;
    struct record *node = NULL;
    while(code[i] != '.')
    {
        node = new record();
        node -> c = code[i];
        node -> next = NULL;
        if(head == NULL)
        {
            head = node;
        }
        else
        {
            temp -> next = node;
        }
        temp = node;
        i++;
    }
    return head;
}

struct record *reverseList(struct record *head)
{
    struct record *prev = NULL;
    struct record *current = head;
    struct record *next = NULL;
    while(current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printReversed(struct record *head)
{
    struct record *temp = head;
    cout << "Answer : ";
    while(temp != NULL)
    {
        cout << temp -> c;
        temp = temp -> next;
    }
    cout << endl;
}

void decode(struct record *head)
{
    if(head != NULL)
    {
        struct record *reversedHead = reverseList(head);
        printReversed(reversedHead);
    }
}

int main()
{
    struct record *head = NULL;
    int choose;
    char code[100];

    while(true)
    {
        cout << "========================" << endl;
        cout << "         Menu           " << endl;
        cout << "========================" << endl;
        cout << " 1) Input secret code   " << endl;
        cout << " 2) Decode              " << endl;
        cout << " 3) Exit                " << endl;
        cout << "Please choose > ";
        cin >> choose;

        switch(choose)
        {
        case 1:
            cout << "Code: ";
            cin >> code;
            head = insertCode(head,code);
            break;
        case 2:
            decode(head);
            break;
        case 3:
            return 0;
        }
    }

    return 0;
}
