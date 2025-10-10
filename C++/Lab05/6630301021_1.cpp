//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record {
	int value;
	struct record *next;
	struct record *prev;
};

struct record *tail = NULL;

void printLists (struct record *head) {
	struct record *temp = head;
	while(temp != NULL) {
		cout << " " << temp->value;
		temp = temp->next;
	}
	cout << endl;
}

struct record *insert (struct record *head, int data) {
	struct record *node, *p;
	if(head == NULL) {
		head = new struct record;
		head->value = data;
		head->next = head->prev = NULL;
		tail = head;
	}else if (head != NULL) {
		node = new struct record;
		if(data <= head->value) {
			node = new struct record;
            node->value = data;
            node->next = head;
            node->prev = NULL;
            head->prev = node;
            head = node;
		}else {
			node->next = p->next;
			p->next->prev = node;
			p->next = node;
			node->prev = p;
		}else {
			node = new struct record;
			if (data > tail->value){
				node->prev = tail;
				tail->next = node;
				node->next = NULL;
				tail = node;
			}else {
				tail = node->next;
			}
		}
	}
	return head;
}

struct record *deleteValue (struct record *head, int data) {
	
}

int main(){
	
	struct record *head = NULL;
	int data, menuNumber;
	
	while (exit) {
        cout << "=====================" << endl;
        cout << "         Menu        " << endl;
        cout << "=====================" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Delete" << endl;
        cout << "3) Print min to max,max to min" << endl;
        cout << "4) Count" << endl;
        cout << "5) Exit" << endl;
        cout << "   Please choose > ";
        cin >> menuNumber;
        
		switch (menuNumber) {
			case 1 : {
				cout << "Insert : ";
				cin >> data;
				head = insert(head, data);
				cout << "List =";
				printLists(head);
			}
			case 2 : {
				cout << "Delete : ";
				cin >> data;
				deleteValue(head, data);
			}
			case 3 : {
			
			break;
			}
			case 4 : {
				
			break;
			}
			case 5 : {
				cout << endl;
				cout << "======Exit======" << endl;
            	exit(0);
			}
		}
	}	
}
