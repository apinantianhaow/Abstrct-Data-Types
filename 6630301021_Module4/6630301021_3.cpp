//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
    struct record *prev;
};

struct record *tail = NULL;

void printNum(struct record *head) {
    struct record *tmp = head;
    while(tmp != NULL) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

struct record *insert(struct record *head, int data){
    struct record *node, *p;
    if(head == NULL) { 
        head = new struct record;
        head -> value = data;
        head -> prev = NULL;
		head -> next = NULL;
        tail = head;
    } else {
        node = new struct record;
        node -> value = data;
        if(data < head -> value) { 
        	node -> next = head;
        	head -> prev = node;
        	head = node;
            node -> prev = NULL; 
        } else {
            p = head;
            while(p -> next != NULL) { 
                if(data < p -> next -> value) { 
                    node -> next = p -> next;
                    p -> next -> prev = node;
                    node -> prev = p;
                    p -> next = node;
                    return head;
                } else {
                    p = p -> next;
                }
            } if(p -> next == NULL){
            	node -> prev = p;
                p -> next = node;
                node -> next = NULL;
                tail = node;
            }
        }
    }
    return head;
}

void MinToMax(struct record *head){
    struct record *tmp = head;
    while(tmp != NULL){
        cout << tmp -> value << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

void MaxToMin(struct record *tail){
    struct record *tmp = tail;
	while(tmp != NULL){
        cout << tmp -> value << " ";
        tmp = tmp -> prev;
    }
    cout << endl;
}

int main() {
    struct record *head = NULL;
    int menuNumber;

    while (exit) {
        cout << "=================================" << endl;
        cout << "               MENU              " << endl;
        cout << "=================================" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Print min to max and max to min" << endl;
        cout << "3) Exit" << endl;
        cout << "         Please choose > ";
        cin >> menuNumber;

        switch (menuNumber) {
            case 1: {
                int data;
                cout << "Insert : ";
                cin >> data;
                head = insert(head, data);
                cout << "List = ";
                printNum(head);
                break;
            }
            case 2: {
            	cout << "Min to max : ";
            	MinToMax(head);
            	cout << "Max to min : ";
            	MaxToMin(tail);
                break;
            }
            case 3: {
                cout << endl;
				cout << "===========Exit Program==========" << endl;
            	exit(0);
            }
        }
    }
    
    return 0;
}
