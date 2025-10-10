//6630301021 Aphinan Thianhao

#include <iostream>
#include <string>
using namespace std;

struct record {
    char c;
    struct record *next;
};

struct record *append(struct record *head, char ch) {
	struct record *node, *temp;
    node = new struct record;
    node->c = ch;
    node->next = NULL;

    if (head == NULL) {
        return node;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;

    return head;
}

void printList(struct record *head) {
    while (head != NULL) {
        cout << head->c;
        head = head->next;
    }
    cout << endl;
}

void encode(struct record *p1, struct record *&p2) {
	struct record *temp;
    string s = "";
    temp = p1;
    while (temp != NULL) {
        s += temp->c;
        temp = temp->next;
    }

    int len = s.length();
    int half = len / 2;

    for (int i = half; i < len; i++) {
        p2 = append(p2, s[i]);
    }

    for (int i = 0; i < half; i++) {
        p2 = append(p2, s[i]);
    }
}

int main() {
    struct record *p1 = NULL;
    struct record *p2 = NULL;
    int menuNum;
    string input;

    while (true) {
        cout << "==============================================" << endl;
        cout << "                     MENU                     " << endl;
    	cout << "==============================================" << endl;
        cout << "1) Input secret code" << endl;
        cout << "2) Encode" << endl;
        cout << "3) Exit" << endl;
        cout << "Please choose > ";
        cin >> menuNum;

        switch(menuNum) {
        	case 1:{
        	cout << "Code: ";
            cin >> input;
            
            // reset p1
            p1 = NULL;
            
            for (int i = 0; i < input.length(); i++) {
                p1 = append(p1, input[i]);
            }
				break;
			}
			case 2:{
				p2 = NULL; // clear list before new encode 
            	encode(p1, p2);
            	cout << "Encode: ";
            	printList(p2);
				break;
			}
			case 3:{
				cout << endl;
				cout << "==================Exit Program================" << endl;
				exit(0);
				break;
			} 
		}
    }

    return 0;
}

