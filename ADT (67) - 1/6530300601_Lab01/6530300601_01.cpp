//6530300601 Sophonwit Thapseng
#include<iostream>

using namespace std;

int main(){
    int n;
    cout << "input : ";
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            for(int k = i;k <= j;k++){
                cout << k;
            }
            cout << " ";
        }
        cout << endl;
    }
    for(int i = n;i >= 1;i--){
        for(int j = i;j >= 1;j--){
            for(int k = i;k >= j;k--){
                cout << k;
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
