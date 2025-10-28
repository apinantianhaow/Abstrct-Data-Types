//6630301021 Aphinan Thianhao

#include <iostream>
#include <string>
using namespace std;

struct Node {
    char value;
    struct Node *left;
    struct Node *right;
};

struct StackNode { 
	struct Node *tree; 
	StackNode *next; 
};

typedef StackNode *Stack;

Stack CreateStack() {
    return NULL;
}

bool IsEmpty(Stack S) {
    return S == NULL;
}

void Push(struct Node *tnode, Stack &S) {
    StackNode *temp = new StackNode;
    temp->tree = tnode;
    temp->next = S;
    S = temp;
}

struct Node *Pop(Stack &S) {
    if (IsEmpty(S)) {
    	return NULL;	
	} else {
		StackNode *temp = S;
    	struct Node *tnode = S->tree;
    	S = S->next;
    	delete (temp);
    	return tnode;
	}
}

struct Node *CreateTreeNode(char value) {
    struct Node *tnode = new struct Node;
    tnode->value = value;
    tnode->left = tnode->right = NULL;
    return tnode;
}

struct Node *BuildExpressionTree(const string &postfix) {
    Stack S = CreateStack();
    for (size_t i = 0 ; i < postfix.length() ; i++) {
    	char ch = postfix[i];
        if (isalnum(ch)) { 
            Push(CreateTreeNode(ch), S);
        } else { 
            struct Node *newNode = CreateTreeNode(ch);
            newNode->right = Pop(S);
            newNode->left = Pop(S);
            Push(newNode, S);
        }
    }
    return Pop(S);
}

void printPreOrder(struct Node *tree) {
    if (tree == NULL){
        return;
    } else {
        cout << tree->value << " ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
    return;
}

void printInOrder(struct Node *tree) {
    if (tree == NULL) {
        return;
    } else {
        printInOrder(tree->left);
        cout << tree->value << " ";
        printInOrder(tree->right);
    }
    return;
}

void printPostOrder(struct Node *tree) {
    if (tree == NULL) {
        return;
    } else {
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        cout << tree->value << " ";
    }
    return;
}

int main() {
    string postfix;
    cout << "Input : ";
    getline(cin, postfix);
    
    string temp = "";
    for (size_t i = 0; i < postfix.length(); i++) {
        if (postfix[i] != ' ')
            temp += postfix[i];
    }
    postfix = temp;

    if (!postfix.empty() && postfix[postfix.length() - 1] == '.') {
        postfix = postfix.substr(0, postfix.length() - 1);
    }

    struct Node *tree = BuildExpressionTree(postfix);

    cout << "Preorder: ";
    printPreOrder(tree);
    cout << endl;

    cout << "Inorder: ";
    printInOrder(tree);
    cout << endl;

    cout << "Postorder: ";
    printPostOrder(tree);
    cout << endl;

    return 0;
}
