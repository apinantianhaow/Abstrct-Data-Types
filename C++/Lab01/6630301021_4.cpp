//6630301021 Aphinan Thianhao

#include <iostream>
using namespace std;

int main(){
	
	int sumTotal=0;
	char a[4][4] = {
	{'T','H','I','S'},
	{'W','A','T','S'},
	{'O','A','H','G'},
	{'F','G','D','T'}};
	
	string dictionary[11] = {"IS","THIS","HIS","AT","HI","IT","TWO","OF","FAT","THAT","HAT"};
	string temp = "";
	
	for(int i=0;i<4;i++) {
		for(int j=i;j<4;j++) {
			for(int k=i;k<=j;k++) {
				temp = temp + a[0][k];
			}
			cout << temp;
            if (temp == dictionary[0]) {
                    cout << " Found: " << ++sumTotal;
                }else if (temp == dictionary[1]) {
                	cout << " Found: " << ++sumTotal;
				}else if (temp == dictionary[2]) {
                	cout << " Found: " << ++sumTotal;
                }
            cout << endl;
			temp.clear();
		}
	}
	
	for(int i=1;i<3;i++) {
		for(int j=i;j<3;j++) {
			for(int k=i;k<=j;k++) {
				temp = temp + a[1][k];
			}
			cout << temp;
            if (temp == dictionary[3]) {
                    cout << " Found: " << ++sumTotal;
                }
			cout << endl;
			temp.clear();
		}
	}
	
	for(int i=1;i<3;i++) {
		for(int j=i;j<3;j++) {
			for(int k=i;k<=j;k++) {
				temp = temp + a[0][k];
			}
			cout << temp;
            if (temp == dictionary[4]) {
                    cout << " Found: " << ++sumTotal;
                }
			cout << endl;
			temp.clear();
		}
	}
	
	for(int i=0;i<=1;i++) {
		for(int j=i;j<=1;j++) {
			for(int k=i;k<=j;k++) {
				temp = temp + a[k][2];
			}
			cout << temp;
            if (temp == dictionary[5]) {
                    cout << " Found: " << ++sumTotal;
                }
			cout << endl;
			temp.clear();
		}
	}
	
	for(int i=0;i<=2;i++) {
		for(int j=i;j<=2;j++) {
			for(int k=i;k<=j;k++) {
				temp = temp + a[k][0];
			}
			cout << temp;
            if (temp == dictionary[6]) {
                    cout << " Found: " << ++sumTotal;
                }
			cout << endl;
			temp.clear();
		}
	}
	
	for(int i=2;i<=3;i++) {
		for(int j=i;j<=3;j++) {
			for(int k=i;k<=j;k++) {
				temp = temp + a[k][0];
			}
			cout << temp;
            if (temp == dictionary[7]) {
                    cout << " Found: " << ++sumTotal;
                }
			cout << endl;
			temp.clear();
		}
	}
	
	for(int i=0;i<4;i++) {
		for(int j=i;j<4;j++) {
			for(int k=i;k<=j;k++) {
				temp = temp + a[3-k][k];
			}
			cout << temp;
            if (temp == dictionary[8]) {
                    cout << " Found: " << ++sumTotal;
                }
			cout << endl;
			temp.clear();
		}
	}
	
	for(int i=3;i>=0;i--) {
		for(int j=i;j>=0;j--) {
			for(int k=i;k>=j;k--) {
				temp = temp + a[k][k];
			}
			cout << temp;
            if (temp == dictionary[9]) {
                    cout << " Found: " << ++sumTotal;
                }else if (temp == dictionary[10]) {
                	cout << " Found: " << ++sumTotal;
				}
			cout << endl;
			temp.clear();
		}
	}
	
	cout << endl;
	cout << "Total = " << sumTotal << endl;
}
