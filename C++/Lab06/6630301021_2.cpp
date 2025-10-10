//6630301021 Aphinan Thianhao

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    char data;
    Node* nextNode;
};

typedef Node* Stack;

Stack CreateStack() {
    Stack newStack = new Node;
    if (!newStack) { 
        cout << "Memory allocation failed" << endl; 
        exit(1); 
    }
    newStack->nextNode = NULL;
    return newStack;
}

void Push(Stack stack, char value) {
    Stack newNode = new Node;
    if (!newNode) { 
        cout << "Memory allocation failed" << endl; 
        exit(1); 
    }
    newNode->data = value;
    newNode->nextNode = stack->nextNode;
    stack->nextNode = newNode;
}

bool IsStackEmpty(Stack stack) {
    return stack->nextNode == NULL;
}

void Pop(Stack stack) {
    if (IsStackEmpty(stack)) { 
        cout << "Stack is empty" << endl; 
        return; 
    }
    Stack tempNode = stack->nextNode;
    stack->nextNode = tempNode->nextNode;
    delete tempNode;
}

char Top(Stack stack) {
    if (!IsStackEmpty(stack)) 
        return stack->nextNode->data;
    
    cout << "Stack is empty" << endl;
    return '\0';
}

bool IsOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int GetPrecedence(char op) {
    if (op == '+' || op == '-') 
        return 1;
    if (op == '*' || op == '/') 
        return 2;
    return 0;
}

string ConvertToPostfix(const string& infix) {
    Stack stack = CreateStack();
    stringstream result;
    bool isPrevDigit = false;

    for (size_t i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        
        if (ch == ' ') 
            continue;

        if (isdigit(ch)) {
            if (isPrevDigit) {
                result << ch;
            } else {
                if (isPrevDigit || !result.str().empty()) {
                    result << ' ';
                }
                result << ch;
                isPrevDigit = true;
            }
        } else {
            isPrevDigit = false;
            if (IsOperator(ch)) {
                while (!IsStackEmpty(stack) && Top(stack) != '(' &&
                       GetPrecedence(Top(stack)) >= GetPrecedence(ch)) {
                    result << ' ' << Top(stack);
                    Pop(stack);
                }
                Push(stack, ch);
            } else if (ch == '(') {
                Push(stack, ch);
            } else if (ch == ')') {
                while (!IsStackEmpty(stack) && Top(stack) != '(') {
                    result << ' ' << Top(stack);
                    Pop(stack);
                }
                if (!IsStackEmpty(stack) && Top(stack) == '(') {
                    Pop(stack);
                }
            }
        }
    }
    if (result.tellp() > 0) {
        result << ' ';
    }
    while (!IsStackEmpty(stack)) {
        result << ' ' << Top(stack);
        Pop(stack);
    }
    return result.str();
}

int main() {
    string infixExpr, postfixExpr;
    char inputChar;

    cout << "Input : ";
    while (cin >> inputChar && inputChar != '.') {
        infixExpr += inputChar;
    }
    postfixExpr = ConvertToPostfix(infixExpr);
    cout << "Output : ";
    
    for (size_t i = 0; i < postfixExpr.length(); ++i) {
        char ch = postfixExpr[i];
        if (ch == ' ') {
            if (i > 0 && postfixExpr[i - 1] != ' ') {
                cout << ' ';
            }
        } else {
            cout << ch;
        }
    }
    cout << endl;
    return 0;
}
