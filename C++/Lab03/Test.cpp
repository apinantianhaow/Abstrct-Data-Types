#include <iostream>
using namespace std;

struct record{
	int value;
	struct record *next; 
};

struct record *insert(struct record *head,int data){
	if (head == NULL){
		head = new struct record;
		head->value = data;
		head->next = NULL;
	}
	return head;
}

int main(){
	while(3){
	int data;
	struct record *head = NULL;
	cout << "Enter : ";
	cin >> data;
	head = insert(head, data);
	cout << head->value << endl;
    }
}
