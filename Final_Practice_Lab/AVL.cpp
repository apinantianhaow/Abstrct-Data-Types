#include <iostream>
using namespace std;

struct Node{
    int value;
    int height;
    struct Node *left;
    struct Node *right;
};

int fheight(struct Node *P){
    if(P == NULL){
        return -1;
    }else{
        return P->height;
    }
}

