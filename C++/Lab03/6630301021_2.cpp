//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct record {
    char data;
    struct record *next;
};

void insert(struct record *&head, char data) {
    if (data == '.') {
        return;
    }
    struct record *node = new struct record;
    node->data = data;
    node->next = NULL; //No info

    if (head == NULL) {
        head = node;
    } else {
        struct record *tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

void decode(struct record *head) {
    struct record *current = head;
    struct record *prev = NULL;
    struct record *next = NULL;
    
	while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    
    struct record *tmp = head;
    cout << "Answer : ";
    while (tmp != NULL) {
        cout << tmp->data;
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    int menuNumber;
    struct record *head = NULL;

    while (true) {
        cout << "==================" << endl;
        cout << "       MENU       " << endl;
        cout << "==================" << endl;
        cout << "   1) Input secret code" << endl;
        cout << "   2) Decode" << endl;
        cout << "   3) Exit" << endl;
        cout << "  Please choose > ";
        cin >> menuNumber;

        switch (menuNumber) {
            case 1: {
                string secretCode;
                cout << "Code : ";
                cin >> secretCode;
                for (int i = 0; i < secretCode.length(); ++i){
                    insert(head, secretCode[i]);
                }
                break;
            }
            case 2: {
                decode(head);
                break;
            }
            case 3: {
            	cout << endl;
				cout << "======Exit Program======" << endl;
                exit(0);
                break;
            }
        }
    }
}
