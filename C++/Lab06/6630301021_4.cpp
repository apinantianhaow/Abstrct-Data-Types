//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

class Queue {
    private:
    Node* front;
    Node* rear;
    public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
        printQueue();
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty  Can’t Dequeue!!!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) {
            rear = NULL;
        }
        cout << "Dequeue " << temp->data << "  Success!" << endl;
        delete temp;
        printQueue();
    }
    bool isEmpty() {
        return front == NULL;
    }
    void printQueue() {
        Node* temp = front;
        cout << "Q =";
        while (temp) {
            cout << " " << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
	
    Queue q;
    int choice, value;

    while(exit) {
        cout << "===============================" << endl;
        cout << "             MENU              " << endl;
        cout << "===============================" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Exit" << endl;
        cout << "Please choose > ";
        cin >> choice;

        switch (choice) {
            case 1:{
				cout << "Enqueue : ";
                cin >> value;
                q.enqueue(value);
                break;
			}
            case 2:{
				q.dequeue();
                break;
			}
            case 3:{
				cout << endl << "========Exiting program========" << endl;
				exit(0);
                break;
			}
        }
    }  
    return 0;
}
