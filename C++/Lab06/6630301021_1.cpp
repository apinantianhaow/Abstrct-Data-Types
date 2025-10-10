//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record {
    char symbol;
    record *next;
};

record *head = NULL;

void Push(record *&S, char symbol) {
    record *node = new record;
    node->symbol = symbol;
    node->next = S;
    S = node;
}

void Pop() {
    if (head != NULL) {
        record *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int checkError(char symbol) {
    if (symbol == '(' || symbol == '{' || symbol == '[') {
        Push(head, symbol);
    } else if (symbol == ')' || symbol == '}' || symbol == ']') {
        if (head == NULL) {
            return 2;
        }
        char top = head->symbol;
        Pop();
        if ((symbol == ')' && top != '(') || 
            (symbol == '}' && top != '{') || 
            (symbol == ']' && top != '[')) {
            return 1;
        }
    }
    return 0; 
}

int main() {
    char c;
    int status = 0;

    cout << "Input : ";
    while ((c = getchar()) != '.') {
        if (c != ' ' && c != '\n') {
            status = checkError(c);
            if (status != 0) {
                break;
            }
        }
    }
    if (status == 0 && head != NULL) {
        status = 3;
    }
    switch (status) {
        case 0:
            cout << "Symbols are balanced." << endl;
            break;
        case 1:
            cout << "Error! Inconsistent symbol." << endl;
            break;
        case 2:
            cout << "Error! No open symbol." << endl;
            break;
        case 3:
            cout << "Error! Excess symbols." << endl;
            break;
    }
    while (head != NULL) {
        Pop();
    }
}
