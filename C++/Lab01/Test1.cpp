#include <iostream>
using namespace std;

int main(){
	
	int number;
	cout << "Input : ";
	cin >> number;
	
	for(int i=1;i<=number;i++){
	  for(int j=i;j<=number;j++){
	  	for(int k=i;k<=j;k++){
	  		cout << k;	
		  }
		cout << " ";
		}
	cout << endl;
	}
	
	for(int i=number;i>=1;--i){
		for(int j=i;j>=1;--j){
			for(int k=i;k>=j;k--){
				cout << k;
			}
			cout << " ";
		}
		cout << endl;
	}
}

