#include <iostream>

using namespace std;

struct record{
    int value;
    struct record *next;
    struct record *prev;
};

struct record *tail = NULL;

struct record *insertNode(struct record *head,int data){
    struct record *node,*p;
    if(head == NULL){ // insert no list
        head = new struct record;
        head -> value = data;
        head -> prev = head -> next = NULL;
        tail = head;
    }else{
        node = new struct record;
        node -> value = data;
        if(data <= head -> value){ // insert min&equal node one
            node -> prev = NULL;
            node -> next = head;
            head -> prev = node;
            head = node;
        }else{
            p = head;
            while(p -> next != NULL){ // loop node 1 -> node N
                if(data < p -> next -> value){ // insert node mid
                    node -> next = p -> next;
                    node -> prev = p;
                    p -> next -> prev = node;
                    p -> next = node;
                    return head;
                }else{
                    p = p -> next;
                }
            }
            if(p -> next == NULL){ //insert last
                node -> next = NULL;
                node -> prev = p;
                p -> next = node;
                tail = node;
            }
        }
    }
    return head;
}

/*
struct record *deleteNode(struct record *head,int data){
    struct record *node,*tmpfree;
    node = head;

    if(head != NULL){
        if(data == head -> value){
            if(head -> next == NULL){  // delete one node
                tmpfree = head;
                head = NULL;
                tail = NULL;
            }else{
                tmpfree = head;
                head = head -> next;
                head -> prev = NULL;
            }
            delete(tmpfree);
        }
    }else if(data == tail -> value){
        if(tail -> prev == NULL){
            tmpfree = tail;
            head = NULL;
            tail = NULL;
        }else{
            tmpfree = tail;
            tail = tail -> prev;
            tail -> next = NULL;
        }
        delete(tmpfree);
    }else{
        while(node != NULL){
            if(node -> next != NULL){
                if(data == node -> next -> value){
                    tmpfree = node -> next;
                    node -> next = tmpfree -> next;
                    if(tmpfree -> next != NULL){
                        tmpfree -> next -> prev = node;
                    }
                    delete(tmpfree);
                    break;
                }
            }else{
                node = node->next;
            }
        }
    }
    return head;
}
*/
/*
void printAll(struct record *head){
    struct record *temp;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        cout << "List : ";
        temp = head;
        while(temp != NULL){
            cout << temp -> value << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}
*/

void MinToMax(struct record *head){
    struct record *tmp = head;
    if(head == NULL){
        cout << "Empty list!" << endl;
    }else{
        while(tmp != NULL){
            cout << tmp -> value << " ";
            tmp = tmp -> next;
        }
    }
}

void MaxToMin(struct record *tail){
    struct record *tmp = tail;
    if(tail == NULL){
        cout << "Empty list!" << endl;
    }else{
        while(tmp != NULL){
            cout << tmp -> value << " ";
            tmp = tmp -> prev;
        }
    }
}

int main(){
    struct record *head = NULL;
    int n,choose;

    while(true){
        cout<< "=========MENU========" << endl;
        cout<< "1) Insert            " << endl;
        cout<< "2) Print min to max & max to min" << endl;
        cout<< "3) Exit              " << endl;
        cout<< "Please choose > ";
        cin >> choose;

        switch(choose){
        case 1:
            cout << "Insert : ";
            cin >> n;
            head = insertNode(head,n);
            //printAll(head);
            cout << endl;
            break;
        case 2:
            cout << "Min to max : ";
            MinToMax(head);
            cout << endl << "Max to min : ";
            MaxToMin(tail);
            cout << endl;
            break;
        case 3:
            return 0;
        }
    }
    return 0;
}
