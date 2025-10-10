//6630300394 teetat pitanupong
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node {
	char value;
	struct Node *next;
};

typedef struct Node *Stack;

Stack CreateStack() {
	Stack S = new struct Node;
	if (S == NULL) cout << "Out of space\n";
	S -> next = NULL;
	return S;
}

void Push(Stack S, char data) {
	Stack node = new struct Node;
	if (node == NULL) cout << "Out of space\n";
	else {
		node -> value = data;
		node -> next = S -> next;
		S -> next = node;	 
	}
}

bool isEmpty(Stack S) {
	return S -> next == NULL;
}

void Pop (Stack S) {
	if(isEmpty(S)) cout << "Empty Stack\n";
	else {
		Stack tmp = S -> next;
		S -> next = S -> next -> next;
		delete tmp;
	}
}

char Top(Stack S) {
	if (!isEmpty(S)) return S -> next -> value;
	cout << "Empty Stack\n";
	return '\0';
}

bool checkOperator(char data) {
    return (data == '+' || data == '-' || data == '*' || data == '/');
}

int peiorityOperator(char data) {
    if (data == '+' || data == '-') return 1;
    if (data == '*' || data == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    Stack St = CreateStack();
    string postfix = "";
    stringstream ss;

    for (int i = 0; i < infix.length(); i++) {
        char data = infix[i];

        if (data == ' ') continue; // Skip spaces

        if (isdigit(data)) {
            ss << data; // Append digit to stringstream
        } else {
            if (ss.str().length() > 0) {
                postfix += ss.str();
                postfix += ' ';
                ss.str(""); // Clear the stringstream
                ss.clear(); // Clear any error flags
            }

            if (checkOperator(data)) {
                while (!isEmpty(St) && Top(St) != '(' && peiorityOperator(Top(St)) >= peiorityOperator(data)) {
                    postfix += Top(St);
                    postfix += ' ';
                    Pop(St);
                }
                Push(St, data);
            } else if (data == '(') {
                Push(St, data);
            } else if (data == ')') {
                while (!isEmpty(St) && Top(St) != '(') {
                    postfix += Top(St);
                    postfix += ' ';
                    Pop(St);
                }
                if (!isEmpty(St) && Top(St) == '(') {
                    Pop(St); // Pop '('
                }
            }
        }
    }
    
    // Append any remaining number
    if (ss.str().length() > 0) {
        postfix += ss.str();
        postfix += ' ';
    }

    // Pop all operators
    while (!isEmpty(St)) {
        postfix += Top(St);
        postfix += ' ';
        Pop(St);
    }
    
    return postfix;
}

int main () {
	Stack S = CreateStack();
	string infix = "";
	char data;
	cout << "Input : ";
	while (true) {
		cin >> data;
		if (data == '.') break;
		infix += data;
	}
	
	string postfix = infixToPostfix(infix);
	cout << "Output : " << postfix;
	
	return 0;
}
