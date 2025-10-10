// 6630301021 Aphinan Thianhao

#include <iostream>
#include <string>
using namespace std;

struct Node;
typedef struct Node* Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(char x, Stack S);
void Pop(Stack S);
char Top(Stack S);

struct Node {
    char value;
    struct Node* next;
};

Stack CreateStack(void) {
    Stack S;
    S = new struct Node;
    if (S == NULL) {
        cout << "Out of Space!!!" << endl;
    }
    S->next = NULL;
    return S;
}

int IsEmpty(Stack S) {
    return S->next == NULL;
}

void MakeEmpty(Stack S) {
    if (S == NULL) {
        cout << "Must use CreateStack first" << endl;
    } else {
        while (!IsEmpty(S)) {
            Pop(S);
        }
        cout << "Stack Empty" << endl;
    }
}

void Push(char x, Stack S) {
    Stack TmpCell;
    TmpCell = new struct Node;
    if (TmpCell == NULL) {
        cout << "Out of space!!!" << endl;
    } else {
        TmpCell->value = x;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

void Pop(Stack S) {
    Stack FirstCell;
    if (IsEmpty(S)) {
        cout << "Stack Underflow" << endl;
    } else {
        FirstCell = S->next;
        S->next = S->next->next;
        delete FirstCell;
    }
}

char Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->next->value;
    } else {
        cout << "Empty Stack!!!" << endl;
        return 0;
    }
}

bool isOpened(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClosed(char c) {
    return c == ')' || c == '}' || c == ']';
}

bool match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    Stack opened = CreateStack();
    Stack closed = CreateStack();
    string s;
    
    cout << "Input : ";
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (isOpened(c)) {
            Push(c, opened);
        } else if (isClosed(c)) {
            if (!IsEmpty(opened) && match(Top(opened), c)) {
                Pop(opened);
            } else {
                Push(c, closed);
            }
        }
    }

    if (!IsEmpty(opened) && !IsEmpty(closed)) {
        cout << "Error : Not match" << endl;
    } else if (!IsEmpty(closed)) {
        cout << "Error : No open symbol" << endl;
    } else if (!IsEmpty(opened)) {
        cout << "Error : stack is not empty" << endl;
    } else {
        cout << "Success" << endl;
    }

    return 0;
}