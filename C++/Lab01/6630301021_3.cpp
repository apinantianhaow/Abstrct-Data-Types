//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

int main(){
	
    int tmp;
    int score[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    cout << "The Number Before Switch : ";
    for (int i=0;i<=9;i++) {
        cout << score[i] << " ";
    }
    cout << endl;

    for (int i=0;i<10/2;i++) {
        tmp=score[i];
        score[i]=score[9 - i];
        score[9 - i]=tmp;
    }
    cout << endl;

    cout << "The Number After Switch : ";
    for (int i=0;i<=9;i++) {
        cout << score[i] << " ";
    }
    cout << endl;
}
