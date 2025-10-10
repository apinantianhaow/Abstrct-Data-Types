#include <iostream>
using namespace std;

void PrintBackToFront(int num) {
    if (num == 0){
        return;
    } else {
        cout << num % 10;
        PrintBackToFront(num / 10);
    }
}

void PrintFrontToBack(int num) {
    if (num == 0) {
        return;
    } else {
        PrintFrontToBack(num / 10);
        cout << num % 10;
    }
}

int CutNumberDigits(int num) {
    return num / 10;
} 

int main() {
    int num;

    while (true) {
        cout << "Input: ";
        cin >> num;

        if (num == 0) break;

        cout << "Output:\n";
        cout << "1) ";
        PrintBackToFront(num);
        cout << endl;

        cout << "2) ";
        PrintBackToFront(CutNumberDigits(num));
        cout << endl;

        cout << "3) ";
        PrintFrontToBack(num);
        cout << endl;

        cout << "4) ";
        PrintFrontToBack(CutNumberDigits(num));
        cout << endl;
    }
}

void PrintBackToFront (int num) { //12345
    if (num == 0){
        return;
    } else {
        cout << num % 10; //5 , 4 , 3
        PrintBackToFront(num / 10); //1234 , 123 , 12
    }
}

void PrintFrontToBack (int num) {
    if (num == 0) {
        return;
    } else {
        PrintFrontToBack(num / 10);
        cout << num % 10;
    }
}

int removeLastDigits (int num) {
    return num / 10;
}