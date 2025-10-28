#include <iostream>
#include <string>
#include <cctype>   // isalnum, isspace
#include <cstring>  // strchr
using namespace std;

struct Node{
    char value;
    struct Node *left;
    struct Node *right;
};

struct StackNode{
    struct Node *tree;
    StackNode *next;
};

typedef StackNode *Stack;

Stack CreateStack(){
    return NULL;
}

ิbool IsEmpty(Stack S){
    return S == NULL
}

void push(struct Node *tree, Stack &S){
    StackNode *newnode = new StackNode;
    newnode->tree = tree;
    newnode->next = S;
    S = newnode;
}

strct Node *Pop(Stack &S){
    if(IsEmpty(S)){
        return NULL;
    }else{
        StackNode *tmpcell = S;
        struct Node *tree = S->tree;
        S = S->next;
        delete(tmpcell);
        return tree;
    }
}

struct Node *CreateTree(char value){
    struct Node *newnode = new struct Node;
    newnode->value = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct Node *BuildExpressionTree(const string &postfix){
    Stack S = CreateStack();
    for(char ch : postfix[i]){
        char ch = postfix[i];
        if(isalnum(ch)){
            push(CreateTree(ch), S);
        }else{
            struct Node *newnode = CreateTree(ch);
            newnode->right = Pop(S);
            newnode->left = Pop(S);
            push(newnode, S);
        }
    }
    return Pop(S);
}