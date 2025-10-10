//Nuengruthai Boonmak 6630300998

#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
    struct record *prev;
};
struct record *head = NULL;
struct record *tail = NULL;

struct record *insert(struct record *head , int data){
    if(head == NULL){
        head = new struct record;
        head->value = data;
        head->next = head->prev = NULL;
        tail = head;
    }
    return  head;
}

int main() {
    int data;
    cout << "Enter : ";
    cin >> data;
    head = insert(head, data);
    cout << "Print From Head : " << head->value << endl;
    cout << "Print From Tail : " <<tail->value << endl;
}