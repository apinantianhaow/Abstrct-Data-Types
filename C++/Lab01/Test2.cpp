#include <iostream>
using namespace std;

int main(){
	
	int number,checkPrimeNum = 0;
	cout << "Input Number : ";
	cin >> number;
	
	for(int i=1;i<=number;i++){
		if (number % i == 0){
			checkPrimeNum++;
		}
	}
	
	if(checkPrimeNum == 1){
		cout << "Not Prime Number";
	}else if (checkPrimeNum == 2){
		cout << "Prime Number";
	}else{
		cout << "Not Prime Number";
	}
}
