#include <iostream>
using namespace std;

int main() {
	int num;
	cout << "Input : ";
	cin >> num;
	
	for(int i = 1 ; i <= num ; i++){
		for(int j = 1 ; j <= num ; j++){
			for(int k = i ; k <= j ; k++){
				cout << k;
			}
			cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}
