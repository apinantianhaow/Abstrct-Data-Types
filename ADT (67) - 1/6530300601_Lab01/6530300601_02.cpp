//6530300601 Sophonwit Thapseng
#include <iostream>

using namespace std;

bool CheckPrime(int n);

int main(){
    int n;
    cout << "input : ";
    cin >> n;
    if(CheckPrime(n)){
        cout << "Prime";
    }else{
        cout << "Not prime";
    }

    return 0;
}

bool CheckPrime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2;i <= n / 2;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
