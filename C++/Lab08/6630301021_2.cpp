//6630301021 Aphinan Thianhao

#include <iostream>
#include <string>
using namespace std;

struct Node {
    char value;
    struct Node* left;
    struct Node* right;
};

typedef Node* StackNode;

struct Stack {
    StackNode node;
    Stack* next;
};

Stack* CreateStack() {
    return NULL;
}

bool IsEmpty(Stack* S) {
    return S == NULL;
}

void Push(StackNode node, Stack*& S) {
    Stack* temp = new Stack;
    temp->node = node;
    temp->next = S;
    S = temp;
}

StackNode Pop(Stack*& S) {
    if (IsEmpty(S)) {
        return NULL;
    }
    Stack* temp = S;
    StackNode node = S->node;
    S = S->next;
    delete temp;
    return node;
}

Node* CreateNode(char value) {
    Node* node = new Node;
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node* BuildExpressionTree(const string& postfix) {
    Stack* S = CreateStack();
    
    for (size_t i = 0; i < postfix.length(); ++i) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            Push(CreateNode(ch), S);
        } else {
            Node* newNode = CreateNode(ch);
            newNode->right = Pop(S);
            newNode->left = Pop(S);
            Push(newNode, S);
        }
    }
    return Pop(S);
}

void PrintInOrder(Node* root) {
    if (root == NULL) return;
    
    PrintInOrder(root->left);
    cout << root->value;
    PrintInOrder(root->right);
}

int main() {
    string postfix;
    cout << "Input postfix: ";
    cin >> postfix;
    
    if (!postfix.empty() && postfix[postfix.length() - 1] == '.') {
        postfix.erase(postfix.length() - 1, 1);
    }
    
    Node* root = BuildExpressionTree(postfix);
    
    cout << "Infix: ";
    PrintInOrder(root);
    cout << endl;

    return 0;
}


