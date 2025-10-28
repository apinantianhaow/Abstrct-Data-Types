//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *find(struct Node *tree, int x) {
    if (tree == NULL) {
        return NULL;
    }
    else if (x < tree->value) {
        return find(tree->left, x);
    }
    else if (x > tree->value) {
        return find(tree->right, x);
    }
    else {
        return tree;  
    }
}

struct Node *find_min(struct Node *tree) {     
 	if(tree==NULL){
 		return NULL;
	 } else {
	 	if(tree->left == NULL){
	 		return tree;
		} else {
			return (find_min(tree->left));
		}
	}
}

struct Node *find_max(struct Node *tree) {     
 	if(tree==NULL){
 		return NULL;
	 } else {
	 	if(tree->right == NULL){
	 		return tree;
		} else {
			return (find_max(tree->right));
		}
	}
}

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

struct Node *dTree(struct Node *tree, int x) {
    struct Node *tmpcell, *child;

    if (tree == NULL) {
        cout << "No Node" << endl;
    }
    else {
        if (x < tree->value) {
            tree->left = dTree(tree->left, x);
        }
        else if (x > tree->value) {
            tree->right = dTree(tree->right, x);
        }
        else if ((tree->left != NULL) && (tree->right != NULL)) {
            tmpcell = find_min(tree->right);
            tree->value = tmpcell->value;
            tree->right = dTree(tree->right, tree->value);
        }
        else {
            tmpcell = tree;
            if (tree->left == NULL) {
                child = tree->right;
            }
            else {
                child = tree->left;
            }

            delete (tmpcell);
            return child;
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
        cout << "2) Delete               " << endl;
        cout << "3) Print min, max       " << endl;
        cout << "4) Print Preorder, Inorder, Postorder " << endl;
        cout << "5) Find                 " << endl;
        cout << "6) Exit                 " << endl;
        cout << "Please choose > ";
        cin >> choose;

        switch (choose) {
        case 1 : {
            cout << "Insert : ";
            cin >> num;
            tree = insert(tree, num);
            break;
        }
        case 2 : {
            cout << "Delete : ";
            cin >> num;
            tree = dTree(tree, num);
            cout << "Success!" << endl;
            break;
        }
        case 3 : {
        	struct Node *minNode = find_min(tree);
            cout << "Min " << minNode->value << endl;
            struct Node *maxNode = find_max(tree);
			cout << "Max " << maxNode->value << endl;
            break;
        }
        case 4 : {
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
        case 5: {
    		cout << "Find : ";
    		cin >> num;
    		struct Node *target = find(tree, num);
    		if (target != NULL) {
        		cout << "Found!" << endl;
    		} else {
        		cout << "Not found!" << endl;
    		}
    		break;
		}
        case 6 : {
            cout << "========= EXIT =========" << endl;
            exit(0);
            break;
        }
    }
}
    return 0;
}
