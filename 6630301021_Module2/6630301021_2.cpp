//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

int printBackToFront(int num) {
    if (num == 0) {
		return false;
    } else {
        cout << num % 10;
        printBackToFront(num / 10);
    }
}

int printFrontToBack(int num) {
    if (num == 0) {
		return false;
    } else {
        printFrontToBack(num / 10);
        cout << num % 10;
    }
}

int removeLastDigit(int num) {
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
        printBackToFront(num);
        cout << endl;

        cout << "2) ";
        printBackToFront(removeLastDigit(num));
        cout << endl;

        cout << "3) ";
        printFrontToBack(num);
        cout << endl;

        cout << "4) ";
        printFrontToBack(removeLastDigit(num));
        cout << endl;
    }

    return 0;
}

