#include <iostream>
using namespace std;

struct Node {
    int value;
    struct Node *right;
    struct Node *left;
};

void PrintPreOrder(struct Node *tree) {
    if (tree == NULL) {
        return;
    } else {
        cout << tree->value << " ";
        PrintPreOrder(tree->left);
        PrintPreOrder(tree->right);
    }
    return;
}

void PrintInOrder(struct Node *tree) {
    if (tree == NULL) {
        return;
    } else {
        PrintInOrder(tree->left);
        cout << tree->value << " ";
        PrintInOrder(tree->right);
    }
    return;
}

void PrintPostOrder(struct Node *tree) {
    if (tree == NULL) {
        return;
    } else {
        PrintPostOrder(tree->left);
        PrintPostOrder(tree->right);
        cout << tree->value << " ";
    }
    return;
}

struct Node *insertTree(struct Node *tree, int x) {
    if (tree == NULL) {
        tree = new struct Node;
        tree->value = x;
        tree->left = tree->right = NULL;
    } else {
        if (x < tree->value) {
            tree->left = insertTree(tree->left, x);
        } else if (x > tree->value) {
            tree->right = insertTree(tree->right, x);
        }
    }
    return tree;
}

int main () {
    struct Node *tree = NULL;
    int choose, num;

    while (true) {
        cout << "========================" << endl;
        cout << "          MENU          " << endl;
        cout << "========================" << endl;
        cout << "1) Insert               " << endl;
        cout << "2) PrintPreOrder        " << endl;
        cout << "3) PrintInOrder         " << endl;
        cout << "4) PrintPostOrder       " << endl;
        cout << "5) Exit                 " << endl;
        cout << "   Please choose > ";
        cin >> choose;

        switch (choose) {
        case 1 : {
            cout << "Insert : ";
            cin >> num;
            tree = insertTree(tree, num);
            break;
        }
        case 2 : {
            cout << "PreOrder : ";
            PrintPreOrder(tree);
            cout << endl << endl;
            break; 
        }
        case 3 : {
            cout << "InOrder : ";
            PrintInOrder(tree);
            cout << endl << endl;
            break;
        }
        case 4 : {
            cout << "PostOrder : ";
            PrintPostOrder(tree);
            cout << endl << endl;
            break;
        }
        case 5 : {
            cout << "========= EXIT =========" << endl;
            exit(0);
        }
        }
    }

    return 0;
}

// struct Node *insert (struct Node *tree, int x) {
//     if (tree == NULL) {
//         tree = new struct Node;
//         tree->value = x;
//         tree->left = tree->right = NULL;
//     } else {
//         if (x < tree->value) {
//             tree->left = insert(tree->left, x);
//         } else if (x > tree->value) {
//             tree->right = insert(tree->right, x);
//         }
//     }
//     return tree;
// }

// void PreOrder (struct Node *tree) {
//     if (tree == NULL) {
//         return;
//     } else {
//         cout << tree->value << endl;
//         PreOrder(tree->left);
//         PreOrder(tree->right);
//     }
//     return;
// }

// void InOrder (struct Node *tree) {
//     if (tree == NULL) {
//         return;
//     } else {
//         InOrder(tree->left);
//         cout << tree->value << endl;
//         InOrder(tree->right);
//     }
//     return;
// }

// void PostOrder (struct Node *tree) {
//     if(tree == NULL) {
//         return;
//     } else {
//         PostOrder(tree->left);
//         PostOrder(tree->right);
//         cout << tree->value << endl;
//     }
//     return;
// }

// struct Node *insert (struct Node *tree, int x) {
//     if (tree == NULL) {
//         tree = new struct Node;
//         tree->value = x;
//         tree->left = tree->right = NULL; 
//     } else {
//         if (x < tree->value) {
//             tree->left = insert(tree->left, x);
//         } else if (x > tree->value) {
//             tree->right = insert(tree->right, x);
//         }
//     }
//     return tree;
// }