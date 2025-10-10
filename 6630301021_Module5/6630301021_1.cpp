//6630301021 Aphinan Thianhao

#include <iostream>
#include <string>
using namespace std;

struct record {
    char c;
    struct record *next;
};

void printList (struct record *head) {
    while (head != NULL) {
        cout << head->c;
        head = head->next;
    }
    cout << endl;
}

struct record *createListFromNumber (string number) {
    struct record* head = NULL, *node;

    for (int i = number.length() - 1; i >= 0; i--) {
        node = new struct record;
        node->c = number[i];
        node->next = head;
        head = node;
    }

    return head;
}

struct record *reverseResult(struct record *head) {
    struct record *prev = NULL;
    struct record *current = head;

    while (current != NULL) {
        struct record *node;
        node = current->next;
        current->next = prev;
        prev = current;
        current = node;
    }

    return prev;
}

struct record *insertEnd(struct record *head, int digit) {
    struct record *node, *temp;
	node = new struct record;
    node->c = digit + '0';
    node->next = NULL;

    if (head == NULL) return node;

    temp = head;
    while (temp->next != NULL) {
    	temp = temp->next;
	}
    temp->next = node;
    
    return head;
}

struct record *addNumber(struct record *p1, struct record *p2) {
    p1 = reverseResult(p1);
    p2 = reverseResult(p2);
    struct record *result = NULL;
    int carry = 0;

    while (p1 != NULL || p2 != NULL || carry > 0) {
        int sum = carry;
        if (p1 != NULL) {
            sum += p1->c - '0';
            p1 = p1->next;
        }
        if (p2 != NULL) {
            sum += p2->c - '0'; 
            p2 = p2->next;
        }
        result = insertEnd(result, sum % 10);
        carry = sum / 10;
    }

    return reverseResult(result);
}

int main() {
    struct record *p1 = NULL;
	struct record *p2 = NULL;
	struct record *sum = NULL;
    int menuNum;
    string input;

    while (true) {
        cout << "================" << endl;
        cout << "      MENU      " << endl;
        cout << "================" << endl;   
        cout << "1. Input p1     " << endl;
        cout << "2. Input p2     " << endl;
        cout << "3. Add          " << endl;
        cout << "4. Exit         " << endl;
        cout << "Please choose > ";
        cin >> menuNum;

        switch (menuNum) {
        case 1: {
            cout << "Input: ";
            cin >> input; 
            p1 = createListFromNumber(input);
            cout << "P1 = " << input << endl;
            break;
        }
        case 2: {
            cout << "Input: ";
            cin >> input;
            p2 = createListFromNumber(input);
            cout << "P2 = " << input << endl;
            break;
        }    
        case 3: {
            if (p1 == NULL || p2 == NULL) {
                cout << "Please input both p1 and p2 first." << endl;
            } else {
                sum = addNumber(p1, p2); 
                cout << "Output = ";
                printList(sum);
            }
            break;
        }
        case 4: {
            cout << "===== Exit =====" << endl;
            exit(0);
        }
        }
    }

    return 0;
}
