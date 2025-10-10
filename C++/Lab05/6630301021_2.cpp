//6630301021 Aphinan Thianhao

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Node;
typedef struct Node *Stack;
int isEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(int x, Stack S);
void Pop(Stack S);
void Top(Stack S);

int main() {
    Stack s1 = NULL;
    s1 = CreateStack();

    int menuNumber, number;

    while (1) {
        cout << "========================" << endl;
        cout << "          MENU          " << endl;
        cout << "========================" << endl;
        cout << "   1) Push              " << endl;
        cout << "   2) Top               " << endl;
        cout << "   3) Pop               " << endl;
        cout << "   4) Pop All           " << endl;
        cout << "   5) Exit              " << endl;
        cout << "      Please choose > ";
        cin >> menuNumber;

        switch (menuNumber) {
            case 1: {
                cout << "Push : ";
                cin >> number;
                Push(number, s1);
                break;
            }
            case 2: {
                Top(s1);
                break;
            }
            case 3: {
                Pop(s1);
                break;
            }
            case 4: {
                MakeEmpty(s1);
                break;
            }
            case 5: {
                cout << "=====End Program=====" << endl;
                exit(0);
                break;
            }
        }
    }
}

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
        cout << "Empty Stack!!!" << endl;
    else {
        Top(S);
        FirstCell = S->next;
        S->next = S->next->next;
        delete (FirstCell);
        cout << "Delete" << endl;
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
        cout << "Top : " << S->next->value << endl;
        return;
    }
    cout << "Empty Stack!!!" << endl;
    return;
}
