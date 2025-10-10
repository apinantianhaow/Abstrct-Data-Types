//6630301021 Aphinan Thianhao

#include <iostream>
#include <string>
using namespace std;

struct Node;
typedef struct Node* Stack;

int IsEmpty (Stack S);
Stack CreateStack (void);
void MakeEmpty (Stack S);
void Push (string x, Stack S);
void Pop (Stack S);
string Top (Stack S);

struct Node {
    string value;  
    struct Node* next;
};

int IsEmpty (Stack S) {
    return S->next == NULL;
}

Stack CreateStack (void) {
    Stack S = new struct Node;
    S->next = NULL;
    return S;
}

void MakeEmpty (Stack S) {
    while (!IsEmpty(S)) {
        Pop(S);
    }
}

void Push (string x, Stack S) {
    Stack TmpCell = new struct Node;
    TmpCell->value = x;
    TmpCell->next = S->next;
    S->next = TmpCell;
}

void Pop (Stack S) {
    if (!IsEmpty(S)) {
        Stack FirstCell = S->next;
        S->next = FirstCell->next;
        delete FirstCell;
    }
}

string Top (Stack S) {
    if (!IsEmpty(S)) {
        return S->next->value;
    }
    return "";
}

int better (string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

Stack insert (string data, Stack head) {
    Stack node = new struct Node;
    node->value = data;
    node->next = NULL;
    if (head == NULL) return node;

    Stack p = head;
    while (p->next != NULL) p = p->next;
    p->next = node;
    return head;
}

Stack check (Stack s, Stack head, string word) {
    while (!IsEmpty(s) && better(Top(s)) >= better(word)) {
        head = insert(Top(s), head);
        Pop(s);
    }
    Push(word, s);
    return head;
}

void printPostfix (Stack head) {
    Stack p = head;
    cout << "Output: ";
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << "." << endl;
}

int main() {
    Stack op = CreateStack();     
    Stack head = NULL;            
    string n, word = "";

    cout << "Input : ";
    getline(cin, n);

    for (int i = 0 ; i < n.size() ; i++) {
        char c = n[i];
        if (isdigit(c)) {
            word += c;
        } else if (c == ' ') {
            if (!word.empty()) {
                head = insert(word, head);
                word = "";
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (!word.empty()) {
                head = insert(word, head);
                word = "";
            }
            string opstr(1, c);
            head = check(op, head, opstr);
        } else if (c == '.') {
            if (!word.empty()) {
                head = insert(word, head);
                word = "";
            }
            break; 
        }
    }

    while (!IsEmpty(op)) {
        head = insert(Top(op), head);
        Pop(op);
    }

    printPostfix(head);

    return 0;
}