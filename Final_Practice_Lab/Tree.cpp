#include <iostream>
using namespace std;

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *find(struct Node *tree, int x){
    if(tree == NULL){
        return NULL;
    }
    else if(x < tree->value){
        return find(tree->left, x);
    }
    else if(x > tree->value){
        return find(tree->right, x);
    }
    else{
        return tree;
    }
}

struct Node *find_min(struct Node *tree){
    if(tree == NULL){
        return NULL;
    }
    else if (tree->left != NULL){
        return find_min(tree->left);
    }
    else{
        return tree;
    }
}

struct Node *find_max(struct Node *tree){
    if(tree == NULL){
        return NULL;
    }
    else if (tree->right != NULL){
        return find_max(tree->right);
    }else{
        return tree;
    }
}

void preorder(struct Node *tree){
    if(tree == NULL){
        return;
    }else{
        cout << tree->value << " ";
        preorder(tree->left);
        preorder(tree->right);
    }
    return;
}

void inorder(struct Node *tree){
    if(tree == NULL){
        return;
    }else{
        inorder(tree->left);
        cout << tree->value << " ";
        inorder(tree->right);
    }
    return;
}

void postorder(struct Node *tree){
    if(tree == NULL){
        return;
    }else{
        postorder(tree->left);
        postorder(tree->right);
        cout << tree->value << " ";
    }
}

struct Node *insert_tree(struct Node *tree, int x){
    if(tree == NULL){
        tree = new struct Node;
        tree->value = x;
        tree->left = tree->right = NULL;
    }else{
        if(x < tree->value){
            tree->left = insert_tree(tree, x);
        }else if(x > tree->value){
            tree->right = insert_tree(tree, x);
        }
    }
    return tree;
}

struct Node *delete_tree(struct Node *tree, int x){
    struct Node *tmpcell, *child;
    if(tree == NULL){
        cout << "No Node" << endl;
    }else{
        if(x < tree->value){
            tree->left = delete_tree(tree->left, x);
        }else if(x > tree->value){
            tree->right = delete_tree(tree->right, x);
        }else if((tree->left != NULL) && (tree->right != NULL)){
            tmpcell = find_min(tree->right);
            tree->value =  tmpcell->value;
            tree->right = delete_tree(tree->right, tree->value);
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
    return tree;
}

int main(){

}