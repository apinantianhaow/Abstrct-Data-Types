//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
    struct record *prev;
};

void printNumber(struct record *head) {
    struct record *tmp = head;
    while (tmp != NULL) {
        cout << " " << tmp->value;
        tmp = tmp->next;
    }
    cout << endl <<endl;
}

struct record *insert(struct record *head, int data) {
    struct record *node = new struct record;
    node->value = data;
    node->next = NULL;
    node->prev = NULL;
    if (head == NULL) {
        head = node;
    } else {
        struct record *current = head;
        struct record *prev = NULL;
        while (current != NULL && current->value < data) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) { 
            node->next = head;
            head->prev = node;
            head = node;
        } else if (current == NULL) { 
            prev->next = node;
            node->prev = prev;
        } else { 
            prev->next = node;
            node->prev = prev;
            node->next = current;
            current->prev = node;
        }
    }
    return head;
}

void printMinToMaxAndMaxToMin(struct record *head) {
    struct record *minToMax = head;
    struct record *maxToMin = head;

    while (maxToMin != NULL && maxToMin->next != NULL) {
        maxToMin = maxToMin->next;
    }
    cout << "Min to max:";
    while (minToMax != NULL) {
        cout << " " << minToMax->value;
        minToMax = minToMax->next;
    }
    cout << endl;
    cout << "Max to min:";
    while (maxToMin != NULL) {
        cout << " " << maxToMin->value;
        maxToMin = maxToMin->prev;
    }
    cout << endl;
}

int main() {
    struct record *head = NULL;
    int menuNumber;

    while (exit) {
        cout << "=========Menu========" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Print min to max & max to min" << endl;
        cout << "3) Exit" << endl;
        cout << "Please choose > ";
        cin >> menuNumber;

        switch (menuNumber) {
            case 1: {
                int data;
                cout << endl << "Insert : ";
                cin >> data;
                head = insert(head, data);
                cout << "Insert :";
                printNumber(head);
                break;
            }
            case 2: {
            	cout << endl;
                printMinToMaxAndMaxToMin(head);
                break;
            }
            case 3: {
                cout << endl;
				cout << "======Exit Program======" << endl;
            	exit(0);
            }
        }
    }
    return 0;
}

