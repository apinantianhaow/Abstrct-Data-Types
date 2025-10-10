//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *left;
	struct node *right;
};

void printInOrder (struct node *tree){
	if(tree == NULL){
		return;
	}else{
		printInOrder(tree->left);
		cout << tree->value << " ";
		printInOrder(tree->right);
	}
}

struct node *find_min(struct node *tree) {     
 	if(tree==NULL)
 		return NULL;
 	else if( tree->left == NULL ){
 		return tree;
	}
 	else {
 		return (find_min(tree->left));
	}
}

struct node *find_max(struct node *tree) {     
 	if(tree == NULL)
 		return NULL;
 	else if(tree->right == NULL) {
 		return tree;
	}
 	else {
 		return (find_max(tree->right));
	}
}

void printLeaves(struct node *tree) {
    if (tree == NULL) {
        return;
    }
    printLeaves(tree->left);
    if (tree->left == NULL && tree->right == NULL) {
        cout << tree->value << " ";
    }
    printLeaves(tree->right);
}

void printNonLeaves(struct node *tree) {
    if (tree == NULL) {
        return;
    }
    printNonLeaves(tree->left);
    if (tree->left != NULL || tree->right != NULL) {
        cout << tree->value << " ";
    }
    printNonLeaves(tree->right);
}

struct node *insert (struct node *tree, int x) {
	if (tree == NULL){
		tree = new struct node;
		tree->value = x;
		tree->left = tree->right = NULL;
	}else {
		if (x < tree->value) {
			tree->left = insert(tree->left, x);
		}else if (x > tree->value) {
			tree->right = insert(tree->right, x);
		}
	}
	return tree;
}

struct node *dTree(struct node *tree, int x) {
    struct node *tmpcell, *child;
    if (tree == NULL) {
        cout << "No Node" << endl;
    } else {
        if (x < tree->value) {
            tree->left = dTree(tree->left, x);
        } else if (x > tree->value) {
            tree->right = dTree(tree->right, x);
        } else if (tree->left != NULL && tree->right != NULL) {
            tmpcell = find_min(tree->right);
            tree->value = tmpcell->value;
            tree->right = dTree(tree->right, tree->value);
        } else {
            tmpcell = tree;
            if (tree->left == NULL) {
                child = tree->right;
            } else {
                child = tree->left;
            }
            delete tmpcell;
            return child;
        }
    }
    return tree;
}

int main(){
	
	struct node *tree = NULL;
	int choose, x;
	
	while (exit) {
		cout << "========MENU========" << endl;
		cout << "1) Insert" << endl;  
		cout << "2) Delete" << endl; 
		cout << "3) Print Inorder, max, min" << endl;
		cout << "4) Print leave node, non leave node" << endl;
		cout << "5) Exit" << endl;
		cout << "Please choose > ";
		cin >> choose;
		
		switch (choose) {
			case 1 : {
				cout << "Enter : ";
				cin >> x;
				tree = insert(tree, x);
				cout << "Success!" << endl;
				break;
			}
			case 2 : {
				cout << "Delete : ";
                cin >> x;
                tree = dTree(tree, x);
                cout << "Data in tree = ";
                printInOrder(tree);
                cout << endl;
                break;
			}
			case 3 : {
				cout << "Inorder : ";
                printInOrder(tree);
                cout << endl;
                if (tree != NULL) {
                    cout << "Max = " << find_max(tree)->value << endl;
                    cout << "Min = " << find_min(tree)->value << endl;
                }
                break;
			}
			case 4 : {
				cout << "Leaves : ";
				printLeaves(tree);
				cout << endl;
				cout << "NonLeaves : ";
				printNonLeaves(tree);
				cout << endl;
				break;
			}
			case 5 : {
				cout << "========EXIT========" << endl;
				exit(0);
				break;
			}
		}
	}
}
