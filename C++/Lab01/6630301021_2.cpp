//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

int main(){
	
	int number,checkPrimeNumber=0;
	cout << "Input : ";
	cin >> number;
	
	for(int i=1;i<=number;i++) {
		if(number % i == 0){
			checkPrimeNumber++;
		}
	}
	if(checkPrimeNumber == 2) {
			cout<< "Prime";
		}else if(checkPrimeNumber == 1) {
			cout<< "Not Prime";
		}else {
			cout<< "Not prime";
		}
}
