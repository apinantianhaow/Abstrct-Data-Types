//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record{
	int value;
	struct record *prev;
	struct record *next;
};
struct record *tail = NULL;

struct record *insert(struct record *head, int data){
	if(head == NULL){
		head = new struct record;
		head->value = data;
		head->next = head->prev = NULL;
		tail = head;
	}
	return head;
}

int main(){
		int data;
		struct record *head = NULL;
		cout << "Enter : ";
		cin >> data;
		cout << endl;
		head = insert(head, data);
 		cout << "Print from head : " << head->value << endl;
 		cout << endl;
 		cout << "Print from tail : " << tail->value << endl;
}
