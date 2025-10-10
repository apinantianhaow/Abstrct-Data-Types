#include <iostream>

using namespace std;

struct record{
    int value;
    struct record *next;
    struct record *prev;
};

struct record *tail = NULL;

void Menu();
struct record *insertNode(struct record *head,int data);
struct record *deleteNode(struct record *head,int data,bool &success);
void printAll(struct record *head);
int countNode(struct record *head);
void MinToMax(struct record *head);
void MaxToMin(struct record *tail);

int main(){
    struct record *head = NULL;
    int num,choose,count = 0;
    bool success = false;

    while(true){
        Menu();
        cin >> choose;
        switch(choose){
        case 1:
            cout << "Insert: ";
            cin >> num;
            head = insertNode(head,num);
            printAll(head);
            break;
        case 2:
            cout << "Delete: ";
            cin >> num;
            head = deleteNode(head,num,success);
            if(success){
                cout << "Success" << endl;
            }else{
                cout << "Fail" << endl;
            }
            //printAll(head);
            break;
        case 3:
            cout << "Min to max: ";
            MinToMax(head);
            cout << "Max to min: ";
            MaxToMin(tail);
            break;
        case 4:
            count = countNode(head);
            cout << "Size = " << count << endl;
            break;
        case 5:
            return 0;
        }
    }

    return 0;
}

void Menu(){
    cout << "=====================" << endl;
    cout << "         MENU        " << endl;
    cout << "=====================" << endl;
    cout << "1) Insert            " << endl;
    cout << "2) Delete            " << endl;
    cout << "3) Print min to max & max to min" << endl;
    cout << "4) Count             " << endl;
    cout << "5) Exit              " << endl;
    cout << "   Please choose >   ";
}

void printAll(struct record *head){
    struct record *tmp;
    if(head == NULL){
        cout << "Empty List!" << endl;
    }else{
        cout << "List = ";
        tmp = head;
        while(tmp != NULL){
            cout << tmp -> value << " ";
            tmp = tmp -> next;
        }
        cout << endl;
    }
}

int countNode(struct record *head){
    struct record *tmp;
    int count = 0;
    if(head == NULL){
        cout << "Empty List!" << endl;
    }else{
        tmp = head;
        while(tmp != NULL){
            count++;
            tmp = tmp -> next;
        }
    }
    return count;
}

void MinToMax(struct record *head){
    struct record *tmp;
    if(head == NULL){
        cout << "Empty List!" << endl;
    }else{
        tmp = head;
        while(tmp != NULL){
            cout << tmp -> value << " ";
            tmp = tmp -> next;
        }
        cout << endl;
    }
}

void MaxToMin(struct record *tail){
    struct record *tmp;
    if(tail == NULL){
        cout << "Empty List!" << endl;
    }else{
        tmp = tail;
        while(tmp != NULL){
            cout << tmp -> value << " ";
            tmp = tmp -> prev;
        }
        cout << endl;
    }
}

struct record *insertNode(struct record *head,int data){
    struct record *node,*p;
    if(head == NULL){ // insert into empty list
        head = new struct record;
        head -> value = data;
        head -> prev = head -> next = NULL;
        tail = head;
    }else{
        node = new struct record;
        node -> value = data;
        if(data <= head -> value){ // insert at beginning
            node -> prev = NULL;
            node -> next = head;
            head -> prev = node;
            head = node;
        }else{
            p = head;
            while(p -> next != NULL){ // insert in middle or end
                if(data < p -> next -> value){ // insert in middle
                    node -> next = p -> next;
                    node -> prev = p;
                    p -> next -> prev = node;
                    p -> next = node;
                    return head;
                }else{
                    p = p -> next;
                }
            }
            if(p -> next == NULL){ // insert at end
                node -> next = NULL;
                node -> prev = p;
                p -> next = node;
                tail = node;
            }
        }
    }
    return head;
}

struct record *deleteNode(struct record *head,int data,bool &success){
    struct record *tmpfree,*p;

    success = false;
    if(head == NULL){
        cout << "Empty List!" << endl;
        return head;
    }else if(head -> value == data){ // delete first node
        tmpfree = head;
        head = head -> next;
        if(head != NULL){
            head -> prev = NULL;
        }else{
            tail = NULL;
        }
        delete(tmpfree);
        success = true;
    }else if(tail -> value == data){ // delete last node
        tmpfree = tail;
        tail = tail -> prev;
        if(tail != NULL){
            tail -> next = NULL;
        }else{
            head = NULL;
        }
        delete(tmpfree);
        success = true;
    }else{ // delete middle node
        p = head;
        while(p != NULL && p -> next != NULL){
            if(p -> next -> value == data){
                tmpfree = p -> next;
                p -> next = p -> next -> next;
                if(p -> next != NULL){
                    p -> next -> prev = p;
                }
                delete(tmpfree);
                success = true;
                break;
            }else{
                p = p -> next;
            }
        }
    }
    return head;
}
