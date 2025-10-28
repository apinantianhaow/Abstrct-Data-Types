#include <iostream>
#include <string>
using namespace std;

struct record {
    char c;
    struct record *next;
};

// ????? linked list ??? string (????????????????????????)
struct record* createListFromString(string number) {
    struct record* head = NULL;

    for (int i = number.length() - 1; i >= 0; i--) {
        struct record* node = new struct record;
        node->c = number[i];
        node->next = head;
        head = node;
    }

    return head;
}

// ???? linked list ??????????? (??????? ? ?????????)
void printListReverse(struct record* head) {
    if (head == NULL) return;
    printListReverse(head->next);
    cout << head->c;
}

// ?????????????????? linked list
void freeList(struct record* head) {
    while (head) {
        struct record* temp = head;
        head = head->next;
        delete temp;
    }
}

// ??? linked list ?????????
struct record* addListsNumber(struct record* l1, struct record* l2) {
    struct record* result = NULL;
    struct record* tail = NULL;
    int carry = 0;

    while (l1 || l2 || carry) {
        int digit1 = (l1 ? l1->c - '0' : 0);
        int digit2 = (l2 ? l2->c - '0' : 0);
        int sum = digit1 + digit2 + carry;

        struct record* node = new struct record;
        node->c = (sum % 10) + '0';
        node->next = NULL;
        carry = sum / 10;

        if (!result) {
            result = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        if (l1 != NULL) {
            l1 = l1->next;
        }

        if (l2 != NULL) {
            l2 = l2->next;
        }
    }

    return result;
}

int main() {
    struct record *p1 = NULL, *p2 = NULL, *sum = NULL;
    string input;
    int choice;

    do {
        cout << "=====================\n";
        cout << "MENU\n";
        cout << "=====================\n";
        cout << "1. Input p1\n";
        cout << "2. Input p2\n";
        cout << "3. Add\n";
        cout << "4. Exit\n";
        cout << "Please choose > ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Input: ";
                cin >> input;
                freeList(p1);
                p1 = createListFromString(input);
                cout << "P1 = " << input << endl;
                break;

            case 2:
                cout << "Input: ";
                cin >> input;
                freeList(p2);
                p2 = createListFromString(input);
                cout << "P2 = " << input << endl;
                break;

            case 3:
                if (!p1 || !p2) {
                    cout << "Please input both p1 and p2 first.\n";
                } else {
                    freeList(sum);
                    sum = addListsNumber(p1, p2);
                    cout << "Output = ";
                    printListReverse(sum);
                    cout << endl;
                }
                break;

            case 4:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 4);

    freeList(p1);
    freeList(p2);
    freeList(sum);

    return 0;
}

