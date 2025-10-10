//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record {
	int value;
	struct record *next;
};

void printList(struct record *head) {
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

struct record *deleteNode(struct record *head, int data){
    struct record *p = head, *prev = NULL;
    if (head == NULL){
        cout << "List is empty!" << endl;
        return head;
    }
    if (head->value == data){
        head = head->next;
        delete p;
        return head;
    }
    while (p != NULL && p->value != data){
        prev = p;
        p = p->next;
    }
    if (p == NULL){
        cout << "Can't delete, no " << data << " in list!!" << endl;
    } else {
        prev->next = p->next;
        delete p;
    }
    return head;
}

void printListReverse(struct record *head) {
    if (head == NULL) return;
    printListReverse(head->next);
    cout << head->value << " ";
}

int countNodes(struct record *head) {
    int count = 0;
    struct record *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printFirstHalfAndSecondHalf(struct record *head) {
    int count = countNodes(head);
    int mid = ( count / 2 );
    int i = 0;
    struct record *temp = head;
    
    cout << "First = ";
    while (temp != NULL && i < mid) {
        cout << temp->value << " ";
        temp = temp->next;
        i++;
    }
    cout << endl;
    cout << "Second = ";
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool findNode(struct record *head, int data) {
    struct record *temp = head;
    while (temp != NULL) {
        if (temp->value == data) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
	
	int menuNumber;
	struct record *head = NULL;
	
	while(exit){
		cout << "========================" << endl;
		cout << "          MENU          " << endl;
		cout << "========================" << endl;
		cout << "   1) Insert       " << endl;
		cout << "   2) Delete       " << endl;
		cout << "   3) Print min to max, max to min" << endl;
		cout << "   4) Count        " << endl;
		cout << "   5) Print first half and second half" << endl;
		cout << "   6) Find         " << endl;
		cout << "   7) Exit         " << endl;
		cout << "      Please choose > ";
		cin >> menuNumber;
		switch(menuNumber){
			case 1:{
				int data;
				cout << "Insert : ";
				cin >> data;
				cout << endl;
				head = insert(head, data);
				cout << "List = ";
				printList(head);
				break;
			}
			case 2:{
				int data;
                cout << "Delete : ";
                cin >> data;
                head = deleteNode(head, data);
                cout << "List = ";
                printList(head);
				break;
			}
			case 3:{
				cout << "Min to max : ";
                printList(head);
                cout << "Max to min : ";
                printListReverse(head);
                cout << endl;
				break;
			}
			case 4:{
				int count = countNodes(head);
				cout <<"Count = " << count << endl;
				cout << endl;
				break;
			}
			case 5:{
				printFirstHalfAndSecondHalf(head);
				break;
			}
			case 6:{
				int data;
				cout << "Find : ";
				cin >> data;
				if (findNode(head, data)){
					cout << "Found!!" << endl;
				}else {
					cout << "Not found!!" << endl;
				}
				break;
			}
			case 7:{
				cout << endl;
				cout << "======Exit Program======" << endl;
            	exit(0);
				break;
			}
		}
	}
}
