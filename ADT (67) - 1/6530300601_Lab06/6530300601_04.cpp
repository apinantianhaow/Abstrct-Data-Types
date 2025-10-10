#include <iostream>

using namespace std;

struct node{
    int value;
    struct node *next;
};

struct FrontBack{
    struct node *front;
    struct node *back;
};
  
typedef struct FrontBack *Queue;

Queue CreateQueue(void);
void Enqueue(int x,Queue q);
void Dequeue(Queue q);
bool IsEmpty(Queue q);
void PrintAllQueue(Queue q);
int Top(Queue q);
void Menu();

int main(){
    Queue q = CreateQueue();
    int choose,num;
    while(true){
        Menu();
        cin >> choose;
        switch(choose){
        case 1:
            cout << "Enqueue : ";
            cin >> num;
            Enqueue(num,q);
            cout << "Q = ";
            PrintAllQueue(q);
            break;
        case 2:
            if(!IsEmpty(q)){
                cout << "Dequeue " << Top(q) << " Success!" << endl;
                Dequeue(q);
                cout << "Q = ";
                PrintAllQueue(q);
            }else{
                cout << "Queue Empty Can�t Dequeue!!!" << endl;
            }
            break;
        case 3:
            return 0;
        }
    }

    return 0;
}

void Menu(){
    cout << "===============================" << endl;
    cout << "             MENU              " << endl;
    cout << "===============================" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Exit" << endl;
    cout << "   Please choose > ";
}

Queue CreateQueue(void){
    Queue q = new FrontBack;
    if(q == NULL){
        cout << "Out of space!!" << endl;
    }
    q -> front = NULL;
    q -> back = NULL;
    return q;
}

void Enqueue(int x,Queue q){
    struct node *newNode = new node;
    if(newNode == NULL){
        cout << "Out of space!!" << endl;
    }
    newNode -> value = x;
    newNode -> next = NULL;
    if(IsEmpty(q)){
        q -> front = newNode;
        q -> back = newNode;
    }else{
        q -> back -> next = newNode;
        q -> back = newNode;
    }
}

void Dequeue(Queue q){
    struct node *tmp;
    if(IsEmpty(q)){
        cout << "Empty Queue!!!" << endl;
    }
    tmp = q -> front;
    q -> front = q -> front -> next;
    if(q -> front == NULL){
        q -> back = NULL;
    }
    delete(tmp);
}

bool IsEmpty(Queue q){
    return(q -> front == NULL);
}

void PrintAllQueue(Queue q){
    struct node *tmp;
    if(IsEmpty(q)){
        cout << "Queue is empty." << endl;
    }
    tmp = q -> front;
    while(tmp != NULL){
        cout << tmp -> value << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

int Top(Queue q){
    if(!IsEmpty(q)){
        return q -> front -> value;
    }else{
        cout << "Empty Queue!!" << endl;
    }
    return 0;
}
