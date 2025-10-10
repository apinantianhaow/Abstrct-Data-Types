//6530300601 Sophonwit Thapseng
#include <iostream>

using namespace std;

int main() {
    int tmp;
    int score[] = {10,20,30,40,50,60,70,80,90,100};
    int sizeScore = sizeof(score) / sizeof(score[0]);

    cout << "ScoreBefor : ";
    for(int i = 0; i < sizeScore;i++){
        cout << score[i] << " ";
    }
    cout << endl;

    for(int i = 0;i < sizeScore / 2;i++){
        tmp = score[i];
        score[i] = score[sizeScore - 1 - i];
        score[sizeScore - 1 - i] = tmp;
    }

    cout << "ScoreAfter : ";
    for(int i = 0; i < sizeScore;i++){
        cout << score[i] << " ";
    }
    cout << endl;

    return 0;
}
