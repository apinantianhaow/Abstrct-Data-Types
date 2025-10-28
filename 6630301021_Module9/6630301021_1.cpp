//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct Node {
    int value;
    int height;
    struct Node *left;
    struct Node *right;
};

int fheight(struct Node *P){   
    if (P == NULL){
        return -1;
    }else{
        return P->height;
    }
}

struct Node *srLeft(struct Node *k2){   
    struct Node *k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
        
    k2->height = max(fheight(k2->left), fheight(k2->right)) + 1;
    k1->height = max(fheight(k1->left), k2->height) + 1;
        
    return k1;
}

struct Node *srRight(struct Node *k2){ 
    struct Node *k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
        
    k2->height = max(fheight(k2->left), fheight(k2->right)) + 1;
    k1->height = max(fheight(k1->right), k2->height) + 1;
        
    return k1;
}

struct Node *drLeft(struct Node *k3){
    k3->left = srRight(k3->left);
    return srLeft(k3);
}

struct Node *drRight(struct Node *k3){
    k3->right = srLeft(k3->right);
    return srRight(k3);
}

struct Node *insert(int x, struct Node *T){
    if (T == NULL) {
        T = new struct Node;
        T->value = x;
        T->left = T->right = NULL;
        T->height = 0;
    } else if (x < T->value) {
        T->left = insert(x, T->left);
        if (fheight(T->left) - fheight(T->right) == 2) {
            if (x < T->left->value)
                T = srLeft(T);
            else
                T = drLeft(T);
        }
    } else if (x > T->value) {
        T->right = insert(x, T->right);
        if (fheight(T->right) - fheight(T->left) == 2) {
            if (x > T->right->value)
                T = srRight(T);
            else
                T = drRight(T);
        }
    }

    T->height = max(fheight(T->left), fheight(T->right)) + 1;
    
    return T;
}

void PrintInorder(struct Node *T){
    if(T == NULL){
        return;
    }else{
        PrintInorder(T->left);
        cout << T->value << " ";
        PrintInorder(T->right);
    }
}

int findHeight(int x, struct Node *T) {
    if(T == NULL){
        return -1;
    }
    if(x == T->value){
        return T->height;
    }else if (x < T->value){
        return findHeight(x, T->left); 
    }else{
        return findHeight(x, T->right);
    } 
}

int main(){
    struct Node *Tree = NULL;
    int choice, val;

    while (true) {
        cout << "=============" << endl;
        cout << "    MENU     " << endl;
        cout << "=============" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Check height" << endl;
        cout << "3) Print Inorder" << endl;
        cout << "Please choose > ";
        cin >> choice;
        
        if(choice == 0){
        	break;
		}

        switch (choice) {
            case 1:{
                cout << "Enter : ";
                cin >> val;
                Tree = insert(val, Tree);  
                cout << "Success!" << endl;
                break;
            }
            case 2:{
                cout << "Check height : ";
                cin >> val;
                cout << "Height = " << findHeight(val, Tree) << endl;
                break;
            }
            case 3:{
                cout << "Print inorder: ";
                PrintInorder(Tree);
                cout << endl;
                break;
            }
        }
    }
    
    return 0;
}
