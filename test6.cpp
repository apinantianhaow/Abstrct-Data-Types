#include <iostream>
using namespace std;

struct record {
    char value;
    record *next;
};

typedef record *stack;

stack MakeStack() {
    stack s = new record{'\0', nullptr};
    return s;
}

bool isEmpty(stack s) {
    return s->next == nullptr;
}

void push(stack s, int value) {
    record *p = new record{value, s->next};
    s->next = p;
}

void pop(stack s) {
    if (isEmpty(s)) return;
    record *p = s->next;
    s->next = p->next;
    delete p;
}

char top(stack s) {
    if (isEmpty(s)) return '\0';
    return s->next->value;
}

bool isOpened(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClosed(char c) {
    return c == ')' || c == '}' || c == ']';
}

bool match(stack s, char c) {
    return top(s) == '(' && c == ')' || top(s) == '{' && c == '}' || top(s) == '[' && c == ']';
}

int main() {
    stack opened = MakeStack();
    stack closed = MakeStack();
    string s;

    cout << "Input : ";
    cin >> s;

    for (char c : s) {
        if (isOpened(c)) {
            push(opened, c);
        } else if (isClosed(c)) {
            if (match(opened, c)) {
                pop(opened);
            } else {
                push(closed, c);
            }
        }
    }


    if (!isEmpty(opened) && !isEmpty(closed)) {
        cout << "Error : Not match";
    } else if (!isEmpty(closed)) {
        cout << "Error : No open symbol";
    } else if (!isEmpty(opened)) {
        cout << "Error : stack is not empty";
    } else {
        cout << "Success";
    }
}