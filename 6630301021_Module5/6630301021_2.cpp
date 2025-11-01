//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct Node;
typedef struct Node *Stack;

int isEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(int x, Stack S);
void Pop(Stack S);
void Top(Stack S);

struct Node {
    int value;
    struct Node *next;
};

Stack CreateStack(void) {
    Stack S;
    S = new struct Node;
    if (S == NULL) {
        cout << "Out of space!!!" << endl;
    }
    S->next = NULL;
    return S;
}

void Push(int x, Stack S) {
    Stack TmpCell;
    TmpCell = new struct Node;
    if (TmpCell == NULL)
        cout << "Out of space!!!" << endl;
    else {
        TmpCell->value = x;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

void Pop(Stack S) {
    Stack FirstCell;
    if (isEmpty(S))
        cout << "Stack underflow" << endl;
    else {
        Top(S);
        FirstCell = S->next;
        S->next = S->next->next;
        delete (FirstCell);
        cout << "Pop success!" << endl;
    }
}

void MakeEmpty(Stack S) {
    if (S == NULL) {
        cout << "Must use CreateStack first" << endl;
    } else {
        while (!isEmpty(S)) {
            Pop(S);
        }
        cout << "Stack Empty" << endl;
    }
}

int isEmpty(Stack S) {
    return S->next == NULL;
}

void Top(Stack S) {
    if (!isEmpty(S)) {
        cout << "Top = " << S->next->value << endl;
        return;
    }
    cout << "Empty Stack!!!" << endl;
    return;
}

int main() {
    Stack s1 = NULL;
    s1 = CreateStack();

    int menuNumber, number;

    while (1) {
        cout << "========================" << endl;
        cout << "          MENU          " << endl;
        cout << "========================" << endl;
        cout << "1) Push              	 " << endl;
        cout << "2) Pop               	 " << endl;
        cout << "3) Top               	 " << endl;
        cout << "4) Exit              	 " << endl;
        cout << "Please choose > ";
        cin >> menuNumber;

        switch (menuNumber) {
            case 1: {
                cout << "Push : ";
                cin >> number;
                Push(number, s1);
                Top(s1);
                break;
            }
            case 2: {
                Pop(s1);
                break;
            }
            case 3: {
                Top(s1);
                break;
            }
            case 4: {
                cout << "========= Exit =========" << endl;
                exit(0);
                break;
            }
        }
    }
    
    return 0;
}
