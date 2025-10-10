//Nuengruthai Boonmak 6630300998

#include <iostream>
using namespace std;

struct record
{
    int value;
    struct record *next;
};

int menu()
{
    int choose;
    cout << "====================" << endl;
    cout << "        MENU        " << endl;
    cout << "====================" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Delete" << endl;
    cout << "3) Print min to max,max to min" << endl;
    cout << "4) Count" << endl;
    cout << "5) Print first half and second half" << endl;
    cout << "6) Find" << endl;
    cout << "7) Exit" << endl;
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

struct record *insert(struct record *head, int data)
{
    struct record *node, *p;
    if (head == NULL)
    {
        head = new struct record;
        head->value = data;
        head->next = NULL;
    }else{
        node = new struct record;
        node->value = data;

        if (data < head->value){
            node->next = head;
            head = node;

        }else{
            p = head;
            while (p->next != NULL){
                if (data < p->next->value){
                    node->next = p->next;
                    p->next = node;
                    break;
                }else{
                    p = p->next;
                }
            }
            if (p->next == NULL){
                node->next = NULL;
                p->next = node;
            }
        }
    }

    return head;
}


struct record *Delete(struct record *head, int data)
{
    struct record *p = head, *prev = NULL;

    if (p != NULL && p->value == data){
        head = p->next;
        delete p;
        return head;
    }

    while (p != NULL && p->value != data){
        prev = p;
        p = p->next;
    }

    if (p == NULL){
        cout << "Can't delete no " << data << " in list!!" << endl;
        return head;
    }
    prev->next = p->next;
    delete p;
    return head;
}

void printList(struct record *head)
{
    cout << "List = ";
    struct record *tmp;
    tmp = head;

    if (tmp == NULL){
        cout << "Empty list\n";
    }else{
        while (tmp){
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
    }
    cout << endl << endl;
}

void printMinMax(struct record *head)
{
    if (head == NULL) return;

    cout << "Min to max : ";
    struct record *tmp = head;
    while (tmp != NULL){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;

    int count = 0;
    tmp = head;
    while (tmp != NULL){
        count++;
        tmp = tmp->next;
    }

    int *values = new int[count];
    tmp = head;
    for (int i = 0; i < count; i++){
        values[i] = tmp->value;
        tmp = tmp->next;
    }

    cout << "Max to min : ";
    for (int i = count - 1; i >= 0; i--){
        cout << values[i] << " ";
    }
    cout << endl;

    delete[] values;
}

void nub(struct record *head)
{
    struct record *tmp;
    int count = 0;
    tmp = head;
    cout << "Count = ";

   while(tmp!=NULL){
    count++;
    tmp=tmp->next;
   }
   cout << count << endl ;

}

void printFirstHalf(struct record *head)
{
    struct record *tmp;
    int length = 0;
    tmp = head;

    while (tmp){
        length++;
        tmp = tmp->next;
    }
    tmp = head;
    cout << "First : ";
    int count = 0;

    while (tmp && count < length / 2){
        cout << tmp->value << " ";
        tmp = tmp->next;
        count++;
    }
    cout << endl;
}

void printSecondHalf(struct record *head)
{
    struct record *tmp;
    int length = 0;
    tmp = head;

    while (tmp){
        length++;
        tmp = tmp->next;
    }
    tmp = head;
    cout << "Second : ";
    int count = 0;

    while (tmp && count < length / 2){
        tmp = tmp->next;
        count++;
    }

    while (tmp){

        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void findList(struct record *head,int data)
{
    struct record *p = head;

    while (p != NULL){

        if (p->value == data){
            cout << "Found!!" << endl;
            return;
        }
        p = p->next;
    }
    cout << "Not found!!" << endl;
}

int main()
{
    int data;
    struct record *head = NULL;
    int choice;

    while (true)
    {
        choice = menu();
        if (choice == 1){
            cout << "Insert : ";
            cin >> data;
            head = insert(head, data);
            printList(head);
        }
        else if (choice == 2){
            cout << "Delete : ";
            cin >> data;
            head = Delete(head,data);
            printList(head);
            cout << endl;
        }
        else if (choice == 3){
            printMinMax(head);
        }
        else if (choice == 4){
            nub(head);
        }
        else if (choice == 5){
            printFirstHalf(head);
            printSecondHalf(head);
        }
        else if (choice == 6){
            cout << "Find : ";
            cin >> data;
            findList(head, data);
        }
        else if (choice == 7){
            break;
        }
    }
}
