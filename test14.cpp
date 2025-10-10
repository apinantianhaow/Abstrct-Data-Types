#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
    struct record *prev;
};

struct record *tail = NULL;

void Print(struct record *head) {
    struct record *temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void PrintMinToMax(struct record *head) {
    struct record *temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void PrintMaxToMin(struct record *tail) { 
    struct record *temp = tail;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}

struct record *Insert(struct record *head, int data) {
    struct record *node, *p;
    if (head == NULL) {
        head = new struct record;
        head->value = data;
        head->next = head->prev = NULL;
        tail = head;
    } else {
        node = new struct record;
        node->value = data;
        if (data < head->value) {
            node->next = head;
            head->prev = node;
            head = node;
            node->prev = NULL;
        } else {
            p = head;
            while (p->next != NULL) {
                if (data < p->next->value) {
                    node->next = p->next;
                    p->next->prev = node;
                    node->prev = p;
                    p->next = node;
                    return head;
                } else {
                    p = p->next;
                }
            }
            node->prev = p;
            p->next = node;
            node->next = NULL;
            tail = node;
        }
    }
    return head;
}

struct record* Delete(struct record *head, int data) {
    struct record *node = head, *tmp;
    if (head == NULL) {
        return NULL;
    }

    // one node
    if (head == tail && head->value == data) {
        delete (head);
        head = tail = NULL;
        return head;
    }

    // First node
    if (head->value == data) {
        tmp = head;
        head = head->next;
        head->prev = NULL;
        delete (tmp);
        return head;
    }

    // Last node
    if (tail->value == data) {
        tmp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete (tmp);
        return head;
    }

    // Middle node
    while (node != NULL) {
        if (node->value == data) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete (node);
            return head;
        }
        node = node->next;
    }

    cout << "Can't delete, no " << data << " in list!!" << endl;
    return head;
}

void PrintMinValue(struct record *head) {
    if (head == NULL) {
        return;
    } else {
        cout << "Min value = " << head->value << endl;
    }
}

void PrintMaxValue(struct record *tail) {
    if (tail == NULL) {
        return;
    } else {
        cout << "Max value = " << tail->value << endl;
    }
}

int main() {
    struct record *head = NULL;
    int menuNumber, data;

    while (true) { 
        cout << "=================================" << endl;
        cout << "               MENU              " << endl;
        cout << "=================================" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Print min to max and max to min" << endl;
        cout << "3) Delete" << endl;
        cout << "4) Exit" << endl;
        cout << "         Please choose > ";
        cin >> menuNumber;

        switch (menuNumber) {
            case 1: {
                cout << "Insert : ";
                cin >> data;
                head = Insert(head, data);
                cout << "List = ";
                Print(head);
                break;
            }
            case 2: {
                cout << "Min to max : ";
                PrintMinToMax(head);
                cout << "Max to min : ";
                PrintMaxToMin(tail);
                break;
            }
            case 3: {
                cout << "Delete : ";
                cin >> data;
                head = Delete(head, data);
                cout << "List = ";
                Print(head);
                break;
            }
            case 4: {
                cout << endl;
                PrintMinValue(head);
                break;
            }
            case 5: {
                cout << endl;
                PrintMaxValue(tail);
                break;
            }
            case 6: {
                cout << endl;
                cout << "===========Exit Program==========" << endl;
                exit(0);
            }
        }
    }

    return 0;
}