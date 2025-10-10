//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

int arr[10];
int index = 0;

void printTheNumber(int arr[],int index) {
	cout << "Output : ";
    for (int i = 0 ; i < index ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int deleteTheNumber(int arr[], int& index, int numberValue) {
    int found = 0;
	for (int i = 0 ; i < index ; ++i) {
        if (arr[i] == numberValue) {
        	found = 1;
            for (int j = i ; j < index - 1 ; ++j) {
                arr[j] = arr[j + 1];
            }
            --index;
            break;
        }
    }
    if (found == 1) {
        printTheNumber(arr, index);
    }else {
        cout << "Number not found in Array." << endl;
    }
}

void insertTheNumber(int arr[],int& index,int numberValue) {
    if (index < 10) {
        arr[index] = numberValue;
        index++;
        printTheNumber(arr,index);
    }else {
        cout << "Array is fully." << endl;
    }
}

void printAllNumber (int arr[],int& index) {
	int calculateMidPoint = (index + 1) / 2; 
	cout << "Print : ";
	for (int i = 0 ; i < index ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Print first half : ";
	for (int i = 0 ; i < calculateMidPoint ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Print second half : ";
	for (int i = calculateMidPoint ; i < index ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sortTheNumber (int arr[],int index) {
	int temp;
    for (int i = 0 ; i < index - 1 ; i++) {
        for (int j = i + 1 ; j < index ; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
	
	int menuNumber;
	
	while(exit){
	cout << "==========Menu==========" << endl;
	cout << "+       1)Insert       +" << endl;
	cout << "+       2)Delete       +" << endl;
	cout << "+       3)Print        +" << endl;
	cout << "+       4)Exit         +" << endl;
	cout << "     Please choose > ";
	cin >> menuNumber;
	switch (menuNumber) {
            case 1: {
                int numberToInsert;
                cout << "Enter : ";
                cin >> numberToInsert;
                insertTheNumber(arr,index,numberToInsert);
                break;
            }
            case 2: {
                int numberToDelete;
                cout << "Delete : ";
                cin >> numberToDelete;
                deleteTheNumber(arr,index,numberToDelete);
                break;
            }
            case 3: {
                printAllNumber(arr, index);
                break;
            }
            case 4: {
            	cout << endl;
				cout << "======Exit Program======" << endl;
            	exit(0);
                break;
			}
        }
    }
}
