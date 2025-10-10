#include <iostream>
#include <vector>

using namespace std;
struct record {
    int value;
    struct record *next;
};

struct record *InsertList(struct record *head,int data){
    struct record *node,*p;
    if(head == NULL){ // insert head NULL
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
    }else{ // head != NULL
        node = new struct record;
        node -> value = data;
        if(data < head -> value){ // insert front
            node -> next = head;
            head = node;
        }else{ // data !< head->value
            p = head;
            while(p != NULL){
                if(p -> next == NULL){ // insert at end
                    p -> next = node;
                    node -> next = NULL;
                    break;
                }else if(data < p -> next -> value){ // insert mid
                    node -> next = p -> next;
                    p -> next = node;
                    break;
                }else{
                    p = p -> next;
                }
            }
        }
    }
    return head;
}

struct record *DeleteList(struct record *head,int data){
    struct record *node = head,*tmpfree;

    if(head == NULL){ // list is empty
        return NULL;
    }

    if(head -> value == data){ // delete head node
        tmpfree = head;
        head = head -> next;
        delete(tmpfree);
        return head;
    }

    while(node -> next != NULL){ // delete middle or end
        if(node -> next -> value == data){
            tmpfree = node -> next;
            node -> next = node -> next -> next;
            delete(tmpfree);
            return head;
        }
        node = node -> next;
    }

    // delete is not found
    cout << "Can't delete no " << data << " in list!!" << endl;

    return head;
};

void PrintList(struct record *head){
    struct record *tmp = head;
    while(tmp != NULL){
        cout << tmp -> value << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

void PrintMinToMax(struct record *head){
    PrintList(head);
}

void PrintMaxToMin(struct record *head){
    vector<int> num;
    struct record *p = head;
    while(p != NULL){
        num.push_back(p -> value);
        p = p->next;
    }
    for(int i = num.size() - 1;i >= 0;--i){
        cout << num[i] << " ";
    }
    cout << endl;
}

int CountList(struct record *head){
    struct record *p = head;
    int countList = 0;
    while(p != NULL){
        countList++;
        p = p -> next;
    }
    return countList;
}

void PrintFirAndSecHalf(struct record *head){
    int size = CountList(head);
    int halfSize = size / 2;

    struct record *p = head;

    cout << "First = ";
    for(int i = 0;i < halfSize;i++){
        cout << p -> value << " ";
        p = p -> next;
    }
    cout << endl;

    cout << "Second = ";
    for(int i = halfSize;i < size;i++){
        cout << p -> value << " ";
        p = p -> next;
    }
    cout << endl;
}

bool FindInList(struct record *head,int data){
    struct record *p = head;
    while(p != NULL){
        if(p -> value == data){
            return true;
        }
        p = p -> next;
    }
    return false;
}

int main(){
    struct record *head = NULL;
    int n,choose;
    while(true){
        cout << "====================Menu===================" << endl;
        cout << "+    1) Insert                            +" << endl;
        cout << "+    2) Delete                            +" << endl;
        cout << "+    3) Print min to max,print max to min +" << endl;
        cout << "+    4) Count                             +" << endl;
        cout << "+    5) Print first half and second half  +" << endl;
        cout << "+    6) Find                              +" << endl;
        cout << "+    7) Exit                              +" << endl;
        cout << "===========================================" << endl;
        cout << "Please choose > ";
        cin >> choose;
        switch(choose){
            case 1:
                cout << "insert : ";
                cin >> n;
                head = InsertList(head,n);
                cout << "List = ";
                PrintList(head);
                cout << endl;
                break;
            case 2:
                cout << "Delete : ";
                cin >> n;
                head = DeleteList(head,n);
                cout << "List : ";
                PrintList(head);
                break;
            case 3:
                cout << "Min to max = ";
                PrintMinToMax(head);
                cout << "Max to min = ";
                PrintMaxToMin(head);
                break;
            case 4:
                cout << "Count = " << CountList(head) << endl;
                break;
            case 5:
                PrintFirAndSecHalf(head);
                break;
            case 6:
                cout << "Find : ";
                cin >> n;
                if(FindInList(head,n)){
                    cout << "Found!!" << endl;
                }else{
                    cout << "Not found!! " << endl;
                }
                break;
            case 7:
                return 0;
        }
    }

    //return 0;
}
