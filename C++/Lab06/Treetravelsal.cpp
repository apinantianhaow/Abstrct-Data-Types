#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *left;
	struct node *right;
};

void print(struct node *tree){
	if (tree != NULL){
		cout << tree->value << " ";
	}
	cout << endl;
}

void printPreorder(struct node *tree){
	if (tree == NULL){
		return;
	}else {
		cout << tree->value << endl;
		print(tree->left);
		print(tree->right);
	}
}

void printInorder(struct node *tree){
	if (tree == NULL){
		return;
	}else {
		print(tree->left);
		cout << tree->value << endl;
		print(tree->right);
	}
}

void printPostorder(struct node *tree){
	if (tree == NULL){
		return;
	}else {
		print(tree->left);
		print(tree->right);
		cout << tree->value << endl;
	}
}

struct node *insert (struct node *tree, int x){
	if (tree == NULL){
		tree = new struct node;
		tree->value = x;
		tree->left = tree->right = NULL;
	} else {
		if (x < tree->value){
			tree->left = insert(tree->left, x);
		}else if (x > tree->value){
			tree->right = insert(tree->right, x);
		}
	}
	return tree;
}

int main(){
	struct node *tree = NULL;
	tree = insert(tree, 15);
	tree = insert(tree, 6);
	tree = insert(tree, 30);
	printPreorder(tree);
	cout << endl;
	printInorder(tree);
	cout << endl;
	printPostorder(tree);
}
