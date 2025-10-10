#include<iostream>
#include<string>
using namespace std;

struct node {
    string value;
    struct node *next;
};
typedef struct node *Stack;

Stack createstack() {
    Stack s = new struct node;
    if (s == NULL) {
        cout << "Out of space" << endl;
        return s;
    }
    s->next = NULL;
    return s;
}

Stack insert(string data, Stack head) {
    Stack node, p;
    if (head == NULL) {
        head = new struct node;
        head->value = data;
        head->next = NULL;
        return head;
    } else {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        node = new struct node;
        node->value = data;
        node->next = NULL;
        p->next = node;
        return head;
    }
}

void push(string data, Stack s) {
    Stack Tmpcell = new struct node;
    if (Tmpcell == NULL) {
        cout << "Out of space" << endl;
    } else {
        Tmpcell->value = data;
        Tmpcell->next = s->next;
        s->next = Tmpcell;
    }
}

bool empty(Stack s) {
    return s->next == NULL;
}

string top(Stack s) {
    if (!empty(s)) {
        return s->next->value;
    }
    return "";
}

void pop(Stack s) {
    Stack firstcell;
    if (empty(s)) {
        cout << "Empty Stack!!!" << endl;
    } else {
        firstcell = s->next;
        s->next = s->next->next;
        delete(firstcell);
    }
}

int better(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

Stack check(Stack s, Stack head, string word) {
    while (!empty(s) && better(top(s)) >= better(word)) {
        string o = top(s);
        head = insert(o, head);
        pop(s);
    }
    push(word, s);
    return head;
}

void printPostfix(Stack head) {
    Stack p = head;
    cout << "Output: ";
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Stack op = createstack();
    Stack head = NULL;
    string n;
    string word = "";

    cout << "Input: ";
    getline(cin, n);

    for (int i = 0; i <= n.size(); i++) {
        char c = n[i];
        if (isdigit(c)) {
            word += c;
        } else if (c == ' ' || i == n.size()) {
            if (!word.empty()) {
                head = insert(word, head);
                word = "";
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (!word.empty()) {
                head = insert(word, head);
                word = "";
            }
            word += c;
            head = check(op, head, word);
            word = "";
        }   else if(c == '.'){
            word+=c;
        }
        }

    while (!empty(op)) {
        string o = top(op);
        head = insert(o, head);
        pop(op);
    }
    head = insert(word,head);

    printPostfix(head);
    return 0;
}
