//Nuengruthai Boonmak 6630300998

#include <iostream>
using namespace std;

struct record {
    char c;
    struct record *next;
};

void printMenu(){
    cout << "========================================" << endl;
    cout << "MENU     MENU     MENU     MENU     MENU" << endl;
    cout << "========================================" << endl;
    cout << "\t 1) Input secret code " << endl;
    cout << "\t 2) Decode " << endl;
    cout << "\t 3) Exit" << endl;
}

void inputSecretCode(record*& head) {
    cout << "\t Code: ";
    string input;
    cin >> input;
    cout << endl;
    record *temp = nullptr;
    for (char ch : input){
        if (ch == '.') {
            break;
        }
        record *newRecord = new record;
        newRecord->c = ch;
        newRecord->next = nullptr;
        
        if (head == nullptr) {
            head = newRecord;
            temp = head;
        } else {
            temp->next = newRecord;
            temp = temp->next;
        }
    }
}

void reverseList(record*& head) {
    record* prev = nullptr;
    record* current = head;
    record* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void decode(record* head) {
    reverseList(head);
    record* temp = head;
    cout << "\t Decoded Code: ";
    while (temp != nullptr) {
        cout << temp->c;
        temp = temp->next;
    }
    cout << endl << endl;
}

int main() {
    int input;
    record *head = nullptr;
    while (true) {
        printMenu();
        cout << "Please choose > ";
        cin >> input;
        switch (input) {
            case 1:
                inputSecretCode(head);
                break;
            case 2:
                decode(head);
                break;
            case 3:
                cout << "Good Bye" << endl;
                exit(0);
            default:
                cout << "\t Please Try again select [1-3] only!!!! " << endl << endl;
                break;
        }
    }
    
    return 0;
}