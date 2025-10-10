//6630301021 Aphinan Thianhao 

#include <iostream>
using namespace std;

int main() {
    int arr[10] = {3, 8, 6, 5, 1, 9, 4, 10, 7, 2};
    int min, indexmin, tmp;

    for (int i = 0; i < 10 - 1; i++) {
        min = arr[i];
        indexmin = i;
        
        for (int j = i + 1; j < 10; j++) {
            if (arr[j] < min) {
                min = arr[j];
                indexmin = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[indexmin];
        arr[indexmin] = tmp;
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

