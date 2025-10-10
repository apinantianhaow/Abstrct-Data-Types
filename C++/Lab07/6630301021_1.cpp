//Aphinan Thianhao 6630301021

#include <iostream>
using namespace std;

struct node {
    int value;
    struct node *left;
    struct node *right;
};

void printPreOrder(struct node *tree) {
    if (tree == NULL) {
        return;
    } else {
        cout << tree->value << " ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void printInOrder(struct node *tree) {
    if (tree == NULL) {
        return;
    } else {
        printInOrder(tree->left);
        cout << tree->value << " ";
        printInOrder(tree->right);
    }
}

void printPostOrder(struct node *tree) {
    if (tree == NULL) {
        return;
    } else {
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        cout << tree->value << " ";
    }
}

void printMaxToMin(struct node *tree) {
    if (tree == NULL) {
        return;
    } else {
        printMaxToMin(tree->right);
        cout << tree->value << " ";
        printMaxToMin(tree->left);
    }
}

struct node *insert(struct node *tree, int x) {
    if (tree == NULL) {
        tree = new struct node;
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

int main() {
    struct node *tree = NULL;
    int choose, x;
    
    while (exit) {
        cout << "========MENU======" << endl;
        cout << "1) Insert         " << endl;
        cout << "2) Print Inorder, Preorder, Postorder, Max to min" << endl;
        cout << "3) Exit           " << endl;
        cout << "   Please choose > ";
        cin >> choose;
        
        switch (choose) {
            case 1 : {
                cout << "Enter: ";
                cin >> x;
                tree = insert(tree, x);
                cout << "Success!" << endl;
                break;
            }
            case 2 : {
                cout << "Preorder  : ";
                printPreOrder(tree);
                cout << endl;
                cout << "Inorder   : ";
                printInOrder(tree);
                cout << endl;
                cout << "Postorder : ";
                printPostOrder(tree);
                cout << endl;
                cout << "Max to min: ";
                printMaxToMin(tree);
                cout << endl;
                break;
            }
            case 3 : {
                exit(0);
                break;
            }
            default : {
                cout << "Invalid choice!" << endl;
            }
        }
    }
    return 0;
}
