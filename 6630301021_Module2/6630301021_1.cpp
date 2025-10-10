//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

int fibonacci(int num) {
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;
	else
		return fibonacci(num - 1) + fibonacci(num - 2);
}

int main(){
	
	for (int num = 0 ; num <= 19 ; num++){
		cout << "F(" << num << ") = " << fibonacci(num) << endl;
	}
	
	return 0;
}
