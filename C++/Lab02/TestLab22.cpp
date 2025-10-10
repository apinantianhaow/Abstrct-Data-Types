#include <iostream>
using namespace std;

int arr[10];
int index = 0;

void printNumber(int arr[], int index) {
    for (int i = 0; i < index; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int deleteTheNumber(int arr[], int& index, int numberValue) {
    int count = 0;
    for (int i = 0; i < index; ++i) {
        if (arr[i] == numberValue) {
            for (int j = i; j < index - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            --index;
            --i; 
            ++count; 
        }
    }
    return count; 
}

void insertTheNumber(int arr[], int& index, int numberValue) {
    if (index < 10) {
        arr[index] = numberValue;
        index++;
        printNumber(arr, index);
    } else {
        cout << "Array is full!" << endl;
    }
}

void printAllNumber(int arr[], int& index) {
    int calculateMidPoint = (index + 1) / 2;
    cout << "All Numbers: ";
    for (int i = 0; i < index; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "First Half: ";
    for (int i = 0; i < calculateMidPoint; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Second Half: ";
    for (int i = calculateMidPoint; i < index; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortTheNumber(int arr[], int index) {
    int temp;
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int menuNumber;
    bool running = true;

    while (running) {
        cout << "==========Menu==========" << endl;
        cout << "+       1) Insert      +" << endl;
        cout << "+       2) Delete      +" << endl;
        cout << "+       3) Print       +" << endl;
        cout << "+       4) Exit        +" << endl;
        cout << "     Please choose > ";
        cin >> menuNumber;

        switch (menuNumber) {
            case 1: {
                int numberToInsert;
                cout << "Enter number to insert: ";
                cin >> numberToInsert;
                insertTheNumber(arr, index, numberToInsert);
                break;
            }
            case 2: {
                int numberToDelete;
                cout << "Enter number to delete: ";
                cin >> numberToDelete;
                int deletedCount = deleteTheNumber(arr, index, numberToDelete);
                cout << "Deleted " << deletedCount << " instances of " << numberToDelete << "." << endl;
                break;
            }
            case 3: {
                printAllNumber(arr, index);
                break;
            }
            case 4: {
                running = false;
                break;
            }
            default:
                cout << "Invalid choice, please choose again." << endl;
        }
    }
    return 0;
}

