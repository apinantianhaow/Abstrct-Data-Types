#include <iostream>
using namespace std;

struct Node{
	int value;
	struct Node *right;
	struct Node *left;	
};

struct Node *insert (struct  Node *tree, int x){
	if(tree == NULL){
		tree = new struct Node;
		tree->value = x;
		tree->left = tree->right = NULL;
	}else{
		if(x < tree->value){
			tree->left = insert(tree, x);
		}else if(x > tree->value){
			tree->right = insert(tree, x);
		}
	}
	return tree;
}

void Preorder(struct Node *tree){
	if(tree == NULL){
		return;
	}else{
		cout << tree->value << " ";
		Preorder(tree->left);
		Preorder(tree->right);
	}
	return;
}

void Inorder(struct Node *tree){
	if(tree == NULL){
		return;
	}else{
		Inorder(tree->left);
		cout << tree->value << " ";
		Inorder(tree->right);
	}
	return;
}

void Postorder(struct Node *tree){
	if (tree == NULL){
		return;
	}else{
		Postorder(tree->left);
		Postorder(tree->right);
		cout << tree->value << " ";
	}
	return;
}

struct Node *find_min(struct Node *tree){
	if(tree == NULL){
		return NULL;
	}else{
		if(tree->left == NULL){
			return tree;
		}else{
			return (find_min(tree->left));
		}
	}
}

struct Node *find_max(struct Node *tree){
	if(tree == NULL){
		return NULL;
	}else{
		if(tree->right == NULL){
			return tree;
		}else{
			return (find_min(tree->right));
		}
	}
}

struct Node *deleteTree (struct Node *tree, int x){
	struct Node *tmpcell, *child;
	if(tree == NULL){
		cout << "No Node" << endl;
	}else{
		if(x < tree->value){
			tree->left = deleteTree(tree, x);
		}else{
			if(x > tree->value){
				tree->right = deleteTree(tree, x);
			}else{
				if(tree->left != NULL && tree->right != NULL){
					tmpcell = find_min(tree->right);
					tree->value = tmpcell->value;
					tree-right = deleteTree(tree->right, tree->value);
				}else{
					tmpcell = tree;
					if(tree->left == NULL){
						child = tree->right;
					}
					if(tree->right == NULL){
						child = tree->left;
					}
					delete(tmpcell);
					return child;
				}
			}
		}
	}
	return tree;
}

int main(){
	
}
