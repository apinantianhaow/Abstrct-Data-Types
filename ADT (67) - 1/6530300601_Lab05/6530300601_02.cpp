#include <iostream>

using namespace std;

struct node{
    int value;
    struct node *next;
};
typedef struct node *Stack;

void Menu();
Stack CreateStack(void);
int IsEmpty(Stack s);
void MakeEmpty(Stack s);
void Push(int x,Stack s);
void Pop(Stack s);
int Top(Stack s);

int main(){
    Stack s = NULL;
    s = CreateStack();

    int num,choose;
    while(true){
        Menu();
        cin >> choose;
        switch(choose){
        case 1:
            cout << "Push : ";
            cin >> num;
            Push(num, s);
            break;
        case 2:
            cout << "Top : ";
            cout << Top(s) << endl;
            break;
        case 3:
            cout << "Top : ";
            cout << Top(s) << endl;
            cout << "Delete" << endl;
            Pop(s);
            break;
        case 4:
            while(!IsEmpty(s)){
                cout << "Top : ";
                cout << Top(s) << endl;
                cout << "Delete" << endl;
                Pop(s);
            }
            if(IsEmpty(s)){
                cout << "Stack Empty" << endl;
            }else{
                cout << "Stack Not Empty" << endl;
            }
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
    cout << "1) Push              " << endl;
    cout << "2) Top               " << endl;
    cout << "3) Pop               " << endl;
    cout << "4) Pop All           " << endl;
    cout << "5) Exit              " << endl;
    cout << "   Please choose >   ";
}

Stack CreateStack(void){
    Stack s = NULL;
    s = new struct node;
    if(s == NULL){
        cout << "Out of space!!" << endl;
    }
    s -> next = NULL;
    return s;
}

void Push(int x,Stack s){
    Stack tmpCell;
    tmpCell = new struct node;
    if(tmpCell == NULL){
        cout << "Out of space!!" << endl;
    }else{
        tmpCell -> value = x;
        tmpCell -> next = s -> next;
        s -> next = tmpCell;
    }
}

void MakeEmpty(Stack s){
    if(s == NULL){
        cout << "Must use CreateStack first" << endl;
    }else{
        while(!IsEmpty(s)){
            Pop(s);
        }
    }
}

int IsEmpty(Stack s){
    return s -> next == NULL;
}

int Top(Stack s){
    if(!IsEmpty(s)){
        return s -> next -> value;
    }else{
        cout << "Empty Stack!!" << endl;
    }
    return 0;
}

void Pop(Stack s){
    Stack firstCell;
    if(IsEmpty(s)){
        cout << "Empty Stack!!!" << endl;
    }else{
        firstCell = s -> next;
        s -> next = s -> next -> next;
        delete(firstCell);
    }
}
