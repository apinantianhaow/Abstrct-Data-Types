//6630300394 teetat pitanupong
#include <iostream>
using namespace std;

struct Node {
    char value;
    struct Node *next;
};
typedef struct Node *Stack;

Stack CreateStack() {
    Stack S = new struct Node;
    if (S == NULL) cout << "Out of Space\n";
    S -> next = NULL;
    return S;
}

bool isEmpty(Stack S) {
    return S -> next == NULL;
}

void Push(Stack S, char data) {
    Stack node = new struct Node;
    if (node == NULL) cout << "Out of Space\n";
    else {
    	node -> value = data;
    	node -> next = S->next;
    	S -> next = node;	
	}
}

void Pop(Stack S) {
    if (isEmpty(S)) cout << "Stack Empty\n";
    else {
    	Stack tmp = S -> next;
    	S -> next = S -> next -> next;
    	delete tmp;
	}
}

char Top(Stack S) {
    if (!isEmpty(S)) return S -> next -> value;
    return '\0';
}

bool isOpenBracket(char data) {
    return data == '(' || data == '{' || data == '[';
}

bool isCloseBracket(char data) {
    return data == ')' || data == '}' || data == ']';
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool match(Stack S, char data) {
    if (isEmpty(S)) return false;
    char open = Top(S);
    return isMatchingPair(open, data);
}


int main () {
    Stack S = CreateStack();
    char data;
    bool error = false;
    
	cout << "Input : ";
    while (true) {
        cin >> data;
        if (data == '.') break;
        
        if (isOpenBracket(data)) {
            Push(S, data);
        } else if (isCloseBracket(data)) {
            if (isEmpty(S)) {
                cout << "Error! no open symbol\n";
                error = true;
                break;
            } else if (match(S, data)) {
                Pop(S);
            } else {
                cout << "Error! Inconsistent symbol\n";
                error = true;
                break;
            }
        } else {
            cout << "Error! Invalid character\n";
            error = true;
            break;
        }
    }

    if (!error) {
        if (isEmpty(S)) cout << "All symbols are balanced\n";
        else cout << "Error! Excess symbols\n";   
    }
    
    return 0;
}

