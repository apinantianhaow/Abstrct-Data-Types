//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
};

void print(struct record *head) {
    struct record *temp = head;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
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

struct record *Delete(struct record *head, int data) {
	struct record *node = head,*tmp;

    if(head == NULL) { 
        return NULL;
    }

    if(head -> value == data) { 
        tmp = head;
        head = head -> next;
        delete(tmp);
        return head;
    }

    while(node -> next != NULL) { 
        if(node -> next -> value == data){
            tmp = node -> next;
            node -> next = node -> next -> next;
            delete(tmp);
            return head;
        }
        node = node -> next;
    }

    cout << "Can't delete not have " << data << " in list!!" << endl;

    return head;
}

int countNumber(struct record *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void PrintMinToMax(struct record *head) {
    print(head);
}

void PrintMaxToMin(struct record *head) {
    struct record *temp;
    if (head == NULL) {
        return;
    }
    
    temp = head->next;
    PrintMaxToMin(temp);

    cout << head->value << " ";
}

void PrintFirstHalfAndSecondHalf(struct record *head) {
    int size = countNumber(head);
    int halfSize = size / 2;
    int i = 0;

    cout << "Print : ";
    print(head);
    
    cout << "First = ";
    struct record *p = head;
    while (i < halfSize && p != NULL) {
        cout << p->value << " ";
        p = p->next;
        i++;
    }
    cout << endl << "Second = ";
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

bool FindInList(struct record *head,int data){
    struct record *p = head;
    while(p != NULL){
        if(p -> value == data){
            return true;
        }
        p = p -> next;
    }
    return false;
}

int main() {
    struct record *head = NULL;
    int num, choose;

    while (true) {
        cout << "======================================" << endl;
        cout << "                 MENU                 " << endl;
        cout << "======================================" << endl;
        cout << "1) Insert                             " << endl;
        cout << "2) Delete                             " << endl;
        cout << "3) Count                              " << endl;
        cout << "4) Print min to max, max to min       " << endl;
        cout << "5) Print first half and second half   " << endl;
        cout << "6) Find                               " << endl;
        cout << "7) Exit                               " << endl;
        cout << "       Please choose > ";
        cin >> choose;

        switch (choose) {
            case 1:{
            	cout << "Insert: ";
                cin >> num;
                head = insert(head, num);
                cout << "List = ";
                print(head);              
				break;
			}
            case 2:{
            	cout << "Delete: ";
                cin >> num;
                head = Delete(head, num);
                cout << "List : ";
                print(head);
                break;
			}
            case 3:{
            	cout << "Count = " << countNumber(head) << endl;
				break;
			}
            case 4:{
            	cout << "Min to max = ";
                PrintMinToMax(head);
                cout << "Max to min = ";
                PrintMaxToMin(head);
                cout << endl;
				break;
			}
            case 5:{
            	PrintFirstHalfAndSecondHalf(head);
				break;
			}
            case 6:{
            	cout << "Find: ";
                cin >> num;
                if (FindInList(head, num)) {
                    cout << "Found!" << endl;
                } else {
                    cout << "Not found!" << endl;
                }
				break;
			}
            case 7:
                cout << endl;
				cout << "=============Exit Program=============" << endl;
            	exit(0);
        }
    } 

    return 0;
}

