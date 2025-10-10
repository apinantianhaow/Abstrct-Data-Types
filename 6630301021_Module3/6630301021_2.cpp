//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record {
	int value;
	struct record *next;
};

void print(struct record *head) {
    struct record *temp = head;
    while (temp != NULL) {
        cout << " " << temp->value;
        temp = temp->next;
    }
    cout << endl << endl;
}

struct record *insert(struct record *head,int data) {
	struct record *p,*node;
 	if (head == NULL) {   
 		head = new struct record;
 		head->value = data;
 		head->next = NULL;
	} else if (head != NULL){
		node = new struct record;
		node->value = data;
		if (data < head->value){
			node->next = head;
			head = node;
		} else { 
			p = head;
			while (p->next != NULL){
				if (data < p->next->value){
					node->next = p->next;
					p->next = node;
					break;
				}else {
					p = p->next;
				}
			}
			if (p->next == NULL){
				node->next = NULL;
				p->next = node;
			}
		}
	}
	return head;
}

int main(){
	
	int menuNum;
	struct record *head = NULL;
	
	while(true){
		cout << "==========MENU==========" << endl;
		cout << "+   1) Insert +         " << endl;
		cout << "+   2) Print  +         " << endl;
		cout << "+   3) Exit   +         " << endl;
		cout << "========================" << endl;
		cout << "      Please choose > ";
		cin >> menuNum;
		switch(menuNum){
			case 1:{
				int data;
				cout << "Enter : ";
				cin >> data;
				cout << endl;
				head = insert(head, data);
				cout << "Output = ";
				print(head);
				break;
			}
			case 2:{
				cout << endl;
				cout << "List : ";
                print(head);
				break;
			}
			case 3:{
				cout << endl;
				cout << "======Exit Program======" << endl;
            	exit(0);
				break;
			}
		}
	}
}
