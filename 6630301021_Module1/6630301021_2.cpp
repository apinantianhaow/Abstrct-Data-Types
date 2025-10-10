//6630301021 Aphinan Thianhao 

#include <iostream>
using namespace std;

int main(){
	int num;
	cout << "input: ";
	cin >> num;
	
	for(int i = 1 ; i <= num ; i++){
		for(int j = i ; j <= num ; j++){
			for(int k = i ; k <= j ; k++){
				cout << k;
			}
			cout << " ";
		}
		cout << endl;
	}

	return 0;
}