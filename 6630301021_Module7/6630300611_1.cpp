// 6630300611 Phimlaphat Khayankit

#include <iostream>
using namespace std;

struct node{
    int value;
    node *left;
    node *right;
};

node *insert(struct node *tree, int x){
    if(tree==NULL){
        tree = new struct node;
        tree -> value = x;
        tree -> left = tree -> right = NULL;
    }else{
        if(x < tree -> value)
            tree -> left = insert(tree -> left, x);
            else if(x > tree -> value)
                tree -> right = insert(tree -> right, x);
    }
    return tree;
}

void preorder(struct node *tree){
    if(tree!=NULL){
        cout << tree -> value << " ";
        preorder(tree -> left);
        preorder(tree -> right);
    }
}

void inorder(struct node *tree){
    if(tree!=NULL){
        inorder(tree -> left);
        cout << tree -> value << " ";
        inorder(tree -> right);
    }
}

void postorder(struct node *tree){
    if(tree!=NULL){
        postorder(tree -> left);
        postorder(tree -> right);
        cout << tree -> value << " ";
    }
}

void print(struct node *tree){
    if(tree==NULL)
        return;
    else{
        cout << tree -> value << endl;
        print(tree -> left);
        print(tree -> right);
        }
        return;
}

int main(){
    struct node *tree = NULL;
    int choice, val;

    do{
        cout << "====================\n";
        cout << "        MENU        \n";
        cout << "====================\n";
        cout << "1) Insert\n";
        cout << "2) Print Preorder, Inorder, Postorder\n";
        cout << "3) Exit\n";
        cout << "Please choose > ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Insert : ";
            cin >> val;
            tree = insert(tree, val);
            cout << "Success\n";
            break;
        case 2:
            cout << "Preorder  : ";
            preorder(tree);
            cout << "\nInorder   : ";
            inorder(tree);
            cout << "\nPostorder : ";
            postorder(tree);
            cout << "\n";
            break;
        case 3:
            cout << "Bye bye!\n";
            break;
        default:
            break;
        }
    }
    while(choice!=3);
    return 0;
}