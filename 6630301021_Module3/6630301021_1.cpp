//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

void printList(int arr[], int size) {
    cout << "Print: ";
    for (int i = 0; i < size; i++)cout << arr[i] << " ";
    cout << endl;

    cout << "Print first half: ";
    for (int i = 0; i < size / 2; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Print second half: ";
    for (int i = size / 2; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

void insert(int arr[], int &size, int data) {
    if (size >= 10) {
        cout << "List is full.\n";
        return;
    }

    int pos = size;
    for (int i = 0; i < size; i++) {
        if (arr[i] > data) {
            pos = i;
            break;
        }
    }
    
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = data;
    size++;

    cout << "Output = ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

void deleteValue(int arr[], int &size, int data) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == data) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Data not found.\n";
        return;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "Output = ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[10];
    int size = 0;
    int menuNum, data;

    while (true) {
        cout << "==========Menu==========" << endl;
        cout << "+    1) Insert         +" << endl;
        cout << "+    2) Delete         +" << endl;
        cout << "+    3) Print          +" << endl;
        cout << "+    4) Exit           +" << endl;
        cout << "========================" << endl;
        cout << "     Please choose > ";
        cin >> menuNum;

        switch (menuNum) {
            case 1:{
            	cout << "Enter: ";
                cin >> data;
                insert(arr, size, data);
				break;
			}
            case 2:{
            	cout << "Delete: ";
                cin >> data;
                deleteValue(arr, size, data);
				break;
			}
            case 3:{
            	printList(arr, size);
				break;
			}
            case 4:{
            	return 0;
			}
			default:{
				cout << "---->Invalid choice<----" << endl;
				break;
			}
        }
    }
}

