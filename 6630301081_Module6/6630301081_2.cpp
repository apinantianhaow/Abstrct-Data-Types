#include<iostream>
#include<string>
using namespace std;

struct node {
    int value;
    struct node *next;
};

typedef struct node *Stack;

Stack createStack() {
    Stack s = new struct node;
    if (s == NULL) {
        cout << "Out of space" << endl;
    } else {
        s->next = NULL;
    }
    return s;
}

void push(int data, Stack s) {
    Stack tmp = new struct node;
    if (tmp == NULL) {
        cout << "Out of space" << endl;
    } else {
        tmp->value = data;
        tmp->next = s->next;
        s->next = tmp;
    }
}

int empty(Stack s) {
    return s->next == NULL;
}

int top(Stack s) {
    if (!empty(s)) {
        return s->next->value;
    }
    return -1;
}

void pop(Stack s) {
    if (!empty(s)) {
        Stack first = s->next;
        s->next = s->next->next;
        delete first;
    } else {
        cout << "Empty stack" << endl;
    }
}

int main() {
    Stack s = createStack();
    string n;
    cout << "Input: ";
    getline(cin, n);
    string word = "";
    for (int i = 0; i < n.size(); i++) {
        char c = n[i];

        if (isdigit(c)) {
            word += c;
        } else if (c == ' ' && word != "") {
            int num = stoi(word);
            push(num, s);
            word = "";
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int a = top(s); pop(s);
            int b = top(s); pop(s);
            int result;
            if (c == '+') result = b + a;
            if (c == '-') result = b - a;
            if (c == '*') result = b * a;
            if (c == '/') result = b / a;
            push(result, s);
        }
    }
    cout << "Result = " << top(s) << endl;

    return 0;
}
