#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
};

void Print (struct record *head) {
    struct record *temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next; 
    }
    cout << endl;
}

struct record *Insert (struct record *head, int data) {
    struct record *node, *p;
    if (head == NULL) {
        head = new struct record;
        head->value = data;
        head->next = NULL;
    }else if (head != NULL) {
        node = new struct record;
        node->value = data;
        if (data < head->value) {
            node->next = head;
            head = node;
        }else{
            p = head;
            while(p->next != NULL) {
                if (data < p->next->value){
                    node->next = p->next;
                    p->next = node;
                    break;
                }else{
                    p = p->next;
                }
            }
            if (p->next == NULL) {
                node->next = NULL;
                p->next = node;
            }
        }
    }
    return head;
}

struct record *DeleteNode (struct record *head, int data) {
    struct record *node = head, *p;
    if (head == NULL) {
        return NULL;
    }

    if(head->value == data) {
        p = head;
        head = head->next;
        delete(p);
        return head;
    }

    while (node->next != NULL){
        if(node->next->value == data) {
            p = node->next;
            node->next = node->next->next;
            delete(p);
            return head;
        }
        node = node->next;
    }

    cout << "Can't Delete Not have " << data << " in Lists" << endl;

    return head;
}

int countNumber (struct record *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void PrintMinToMax (struct record *head) {
    Print(head);
}

void PrintMaxToMin (struct record *head) {
    struct record *temp;
    if (head == NULL) {
        return;
    }

    temp = head->next;
    PrintMaxToMin(temp);

    cout << head->value << " ";
}

void PrintFirstHalfAndSecondHalf (struct record *head) {
    int size = countNumber(head);
    int halfsize = size / 2;
    int i = 0;

    cout << "First Half : ";
    struct record *p = head;
    while (i < halfsize && p != NULL) {
        cout << p->value << " ";
        p = p->next;
        i++;
    }

    cout << endl << "Second Half : ";
    while (p != NULL){
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

void PrintMinValue(struct record *head) {
    if (head == NULL) {
        return;
    } else {
        cout << "Min value = " << head->value << endl;
    }
}

void PrintMaxValue(struct record *head) {
    if (head == NULL) {
        return;
    } else {
        struct record *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        cout << "Max value = " << p->value << endl;
    }
}

bool FindinLists (struct record *head, int data) {
    struct record *temp = head;
    while(temp != NULL) {
        if(temp->value == data){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    struct record *head = NULL;
    int choose, num;

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
        cout << "7) PrintMinValue                      " << endl;
        cout << "8) PrintMaxValue                      " << endl;
        cout << "9) Exit                               " << endl;
        cout << "       Please choose > ";
        cin >> choose;

        switch (choose) {
            case 1:{
            	cout << "Insert: ";
                cin >> num;
                head = Insert(head, num);
                cout << "List = ";
                Print(head);              
				break;
			}
            case 2:{
            	cout << "Delete: ";
                cin >> num;
                head = DeleteNode(head, num);
                cout << "List : ";
                Print(head);
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
                if (FindinLists(head, num)) {
                    cout << "Found!" << endl;
                } else {
                    cout << "Not found!" << endl;
                }
				break;
			}
            case 7:{
                PrintMinValue(head);
                break;
            }
            case 8:{
                PrintMaxValue(head);
                break;
            }
            case 9:
                cout << endl;
				cout << "=============Exit Program=============" << endl;
            	exit(0);
        }
    } 
    return 0;
}