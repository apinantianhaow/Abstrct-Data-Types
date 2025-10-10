//6530300601 Sophonwit Thapseng
#include <iostream>

using namespace std;

struct record{
    int value;
    struct record *next;
};

struct record *insert(struct record *head,int data){
    struct record *node,*p;
    if(head == NULL){
        head = new struct record;
        head -> value = data;
        head -> next = NULL;
    }
    return head;
};

int main(){
    struct record *head = NULL;
    head = insert(head,15);
    cout << head -> value;

    return 0;
}
