// 6530300601 Sophonwit Thapseng
#include <iostream>

using namespace std;

int Fibonacci(int n);

int main(){
    int n;
    cin >> n;
    for(int i = 0;i <= n;i++){
        cout << "f(" << i << ") = " << Fibonacci(i) << endl;
    }
    return 0;
}

int Fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
