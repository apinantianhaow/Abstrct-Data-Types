//6630300262 Natthaphon Philachai
#include <iostream>
#include <cstdlib> // for math such as abs
using namespace std;

int main(){
	char a[4][4] = {{'T','H','I','S'},
					{'W','A','T','S'},
					{'O','A','H','G'},
					{'F','G','D','T'}};
	string db[17] = {"IS","THIS","HIS","AT","YOU","HI","IT","TWO",
					"OF","FAT","THAT","HAT", "GOD","CAT",
					"HAT", "AN","FOUR"};
	string temp = "";
	int count=0;
	
	//Horizontal
	for(int round = 0;round <4;round++){
		for(int i = 0;i<4;i++){
			for(int j = i;j<4;j++){
				for(int k = i;k<=j;k++){
					temp = temp + a[round][k];
				}
				cout << temp;
				
				for(int i = 0;i < 17;i++){
					if(temp == db[i]){
						count++;
						cout << " Found "<<count;
						db[i] = "";
						
					}
				}
				cout << "\n";
				temp.clear();	
			}
		}
	}
	cout << endl;
	//Vertical
	for(int round = 0;round<4;round++){
		for(int i = 0;i<4;i++){
			for(int j = i;j<4;j++){
				for(int k = i;k<=j;k++){
					temp = temp + a[k][round];
				}
				cout << temp;
				
				for(int i = 0;i < 17;i++){
					if(temp == db[i]){
						count++;
						cout << " Found "<<count;
						db[i] = "";
						
					}
				}
				cout << "\n";
				temp.clear();
			}
		}	
	}
	
	//x cross R-L DownToUp
	for(int i = 3;i>=0;i--){
		for(int j = i;j>=0;j--){
			for(int k = i;k>=j;k--){
				temp = temp + a[k][k];
				//cout << a[k][k] <<"\nK = "<<k<<"\n";
			}
			cout << temp;
		
			for(int i = 0 ; i <17;i++){
				if(temp == db[i]){					
				count++;
					cout<<" Found "<<count;
					db[i] = "";
				}
		}
		cout << "\n";
		temp.clear();
			
		}
	}
	
	//x cross L-R DownToUp
	for(int i = 3;i >= 0;i--){
		for(int j = i;j <= 3;j++){
			for(int k = abs(i-3);k >=abs(j-3);k--){
				cout << "\ni = "<<i<<" j = "<<j<<" k = "<<k<<"\n";
				cout << a[i][k];
				
			}
			cout << "\n";
		}
		
	}
		
	
	//For test
	cout << "Count = "<<count;					
	return 0;
}

