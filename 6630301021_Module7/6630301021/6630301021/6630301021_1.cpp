//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *insert (struct Node *tree, int x) {
    if(tree == NULL){
        tree = new struct Node;
        tree->value = x;
        tree->left = tree->right = NULL;
    } else {
        if (x < tree->value) {
            tree->left = insert(tree->left, x);
        } else if (x > tree->value) {
            tree->right = insert(tree->right, x);
        }
    }
    return tree;
}

void printPreOrder (struct Node *tree) {
    if (tree == NULL){
        return;
    } else {
        cout << tree->value << " ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
    return;
}

void printInOrder (struct Node *tree) {
    if (tree == NULL) {
        return;
    } else {
        printInOrder(tree->left);
        cout << tree->value << " ";
        printInOrder(tree->right);
    }
    return;
}

void printPostOrder (struct Node *tree) {
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
    struct Node *tree = NULL;
    int choose, num;

    while (true) {
        cout << "========================" << endl;
        cout << "          MENU          " << endl;
        cout << "========================" << endl;
        cout << "1) Insert               " << endl;
        cout << "2) Print Preorder, Inorder, Postorder " << endl;
        cout << "3) Exit                 " << endl;
        cout << "Please choose > ";
        cin >> choose;

        switch (choose) {
        case 1 : {
            cout << "Insert : ";
            cin >> num;
            tree = insert(tree, num);
            cout << "Success" << endl;
            break;
        }
        case 2 : {
            cout << "Preorder : ";
            printPreOrder(tree);
            cout << endl;
            cout << "Inorder : ";
            printInOrder(tree);
            cout << endl;
            cout << "Postorder : ";
            printPostOrder(tree);
            cout << endl;
            break; 
        }
        case 3 : {
            cout << "========= EXIT =========" << endl;
            exit(0);
            break;
        }
    }
}
    return 0;
}