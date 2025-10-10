#include <iostream>

using namespace std;

int InsertArr(int arr[],int sizeArr,int curSize,int n);
int DeleteArr(int arr[],int curSize,int delNum);
void PrintArr(int arr[],int curSize);

int main(){
    int i,n,choose,index;
    int arr[10] = {0};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    int curSize = 0;

    while(true){
        cout << "==========Menu========" << endl;
        cout << "+     1) Insert      +" << endl;
        cout << "+     2) Delete      +" << endl;
        cout << "+     3) Print       +" << endl;
        cout << "+     4) Exit        +" << endl;
        cout << "======================" << endl;
        cout << "Please choose > ";
        cin >> choose;

        switch(choose){
        case 1:
            cout << "Enter : ";
            cin >> n;
            curSize = InsertArr(arr,sizeArr,curSize,n);
            cout << "Output = ";
            for(i = 0;i < curSize;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 2:
            cout << "Delete : ";
            cin >> n;
            curSize = DeleteArr(arr,curSize,n);
            cout << "Output = ";
            for(i = 0;i < curSize;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 3:
            PrintArr(arr,curSize);
            break;
        case 4:
            cout << "Bye !!" << endl;
            return 0;
        }
    }
}

int InsertArr(int arr[],int sizeArr,int curSize,int n){
    if(curSize >= sizeArr){ // Check if array is full
        cout << "Array is full" << endl;
        return curSize;
    }

    int i,index = curSize;
    for(i = 0;i < curSize;i++){ // Find insert value
        if(n < arr[i]){
            index = i;
            break;
        }
    }
    if(i == curSize){ // n is bigger than all element
        index = curSize;
    }

    //cout << "Index to insert : " << index << endl;

    for(i = curSize - 1;i >= index;i--){ // Move element backward
        arr[i + 1] = arr[i];
    }
    arr[index] = n;
    curSize++;

    return curSize; // Return new size Array
}

int DeleteArr(int arr[],int curSize,int n){
    int i,index = -1;
    for(i = 0;i < curSize;i++){
        if(n == arr[i]){
            index = i;
            break;
        }
    }
    if(index == -1){
        cout << "Element not found" << endl;
        return curSize;
    }

    for(i = index;i < curSize - 1;i++){ // Move element forward
        arr[i] = arr[i + 1];
    }
    curSize--;

    return curSize;
}

void PrintArr(int arr[],int curSize){
    int halfSize = curSize / 2;
    cout << "Print : ";
    for(int i = 0;i < curSize;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Print first half : ";
    for(int i = 0;i < halfSize;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Print second half : ";
    for(int i = halfSize;i < curSize;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
