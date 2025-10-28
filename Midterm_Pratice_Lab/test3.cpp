#include <iostream>
using namespace std;

int main() {
	int num, count = 0;
	cout << "Input : ";
	cin >> num;
	
	for(int i = 1 ; i <= num ; i++){
		if(num % i == 0){
			count++;
		}
	}
	
	if(count == 2){
		cout << "Prime";
	}else if(count == 1){
		cout << "Not Prime";
	}else{
		cout << "Not prime";
	}
	return 0;
}
