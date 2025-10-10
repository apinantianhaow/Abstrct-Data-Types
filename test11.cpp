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

struct record *insert (struct record *head, int data) {
    struct record *node, *p;
    if (head == NULL) {
        head = new struct record;
        head->value = data;
        head->next = NULL;
    } else if (head != NULL) {
        node = new struct record;
        node->value = data;
        if (data < head->value) {
            node->next = head;
            head = node;
        } else {
            p = head;
            while (p->next != NULL) {
                if (data < p->next->value) {
                    node->next = p->next;
                    p->next = node;
                    break;
                } else {
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

struct record *deleteNode (struct record *head, int data) {
    struct record *node = head, *temp;
    if (head == NULL) {
        return NULL;
    }

    if (head->value == data) {
        temp = head;
        head = head->next;
        delete(temp);
        return head;
    }

    while (node->next != NULL) {
        if (node->next->value == data) {
            temp = node->next;
            node->next = node->next->next;
            delete(temp);
            return head;
        }
        node = node->next;
    }

    cout << "Can't Delete This Not have " << data << " in Lists" << endl;

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

    cout << "First half : ";
    struct record *p = head;
    while(i < halfsize && p != NULL){
        cout << p->value << " ";
        p = p->next;
        i++;
    }

    cout << endl << "Second half : ";
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

bool FindinLists (struct record *head, int data) {
    struct record *p = head;
    while (p != NULL){
        if (p->value == data) {
            return true;
        } 
        p = p->next;
    }
    return false;
}

int main() {
    struct record *head = NULL;
    int choose, num;

    while (true) {
        cout << "Choose : ";
        cin >> choose;

        switch (choose) {
            case 1 : {
                cout << "Insert : ";
                cin >> num;
                head = insert(head, num);
                cout << "Lists : ";
                Print(head);
                break;
            }
            case 2 : {
                cout << "Delete : ";
                cin >> num;
                head = deleteNode(head, num);
                cout << "Lists : ";
                Print(head);
                break;
            }
            case 3 : {
                cout << "Count : " << countNumber(head) << endl;
                break;
            }
            case 4 : {
                cout << "Min To Max : ";
                PrintMinToMax(head);
                cout << "Max To Min : ";
                PrintMaxToMin(head);
                cout << endl;
                break;
            }
            case 5 : {
                PrintFirstHalfAndSecondHalf(head);
                break;
            }
            case 6 : {
                cout << "Find : ";
                cin >> num;
                if (FindinLists(head, num)) {
                    cout << "Found!" << endl;
                } else {
                    cout << "Not Found!" << endl;
                }
                break;
            }
            case 7 : {
                exit(0);
            }
            default :
                break;
        }
    }
}

// void PrintFirstHalfAndSecordHalf (struct record *head) {
//     int size = countNumber(head);
//     int halfsize = size / 2;
//     int i = 0;

//     cout << "First Half : ";
//     struct record *p = head;
//     while (i < halfsize && p != NULL) {
//         cout << p->value << " ";
//         p = p->next;
//         i++;
//     }

//     cout << endl << "Second Half : ";
//     while (p != NULL) {
//         cout << p->value << " ";
//         p = p->next;
//     }
//     cout << endl;
// }

bool FindinLists (struct record *head, int data) {
    struct record *p = head;
    while(p != NULL) {
        if (p->value == data) {
            return true;
        }
        p = p->next;
    }
    return false;
}