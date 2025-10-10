//6630300394 Teetat Pitanupong
#include <iostream>
using namespace std;

int main () {
	char a[4][4] = {{'T','H','I','S'},
				    {'W','A','T','S'},
				    {'O','A','H','G'},
				    {'F','G','D','T'}};
				   
	string tmp="",dic[11] = {"IS","THIS","HIS","AT","HI","IT","TWO","OF","THAT","HAT","FAT"};
	int total=0;
	for (int i = 2; i <= 3;i++){
		tmp = tmp + a[0][i];
		cout << tmp; 
		if (tmp == dic[0]){
			cout << " Found " << ++total << endl;
			tmp.clear();
			for(int i = 0 ;i <=3 ; i++){
				tmp = tmp + a[0][i];
				cout << tmp;
				if(tmp == dic[1]){
					cout << " Found " << ++total<< endl;
					tmp.clear();
					for(int i = 1 ;i <=3 ; i++){
						tmp = tmp + a[0][i];
						cout << tmp;
						if(tmp == dic[2]){
							cout << " Found " << ++total<< endl;
							tmp.clear();
							for(int i = 1 ;i <=2 ; i++){
								tmp = tmp + a[1][i];
								cout << tmp;
								if(tmp == dic[3]){
									cout << " Found " << ++total<< endl;
									tmp.clear();
									for(int i = 1 ;i <=2 ; i++){
										tmp = tmp + a[0][i];
										cout << tmp;
										if(tmp == dic[4]){
											cout << " Found " << ++total<< endl;
											tmp.clear();
											for(int i = 0 ;i <=1 ; i++){
												tmp = tmp + a[i][2];
												cout << tmp;
												if(tmp == dic[5]){
													cout << " Found " << ++total<< endl;
													tmp.clear();
													for(int i = 0 ;i <=2 ; i++){
														tmp = tmp + a[i][0];
														cout << tmp;
														if(tmp == dic[6]){
															cout << " Found " << ++total<< endl;
															tmp.clear();
															for(int i = 2 ;i <=3 ; i++){
																tmp = tmp + a[i][0];
																cout << tmp;
																if(tmp == dic[7]){
																	cout << " Found " << ++total<< endl;
																	tmp.clear();
																	for(int i = 3 ;i >=0 ; i--){
																		tmp = tmp + a[i][i];
																		cout << tmp;
																		if(tmp == dic[8]){
																			cout << " Found " << ++total<< endl;
																			tmp.clear();
																			for(int i = 2 ;i >=0 ; i--){
																				tmp = tmp + a[i][i];
																				cout << tmp;
																				if(tmp == dic[9]){
																					cout << " Found " << ++total<< endl;
																					tmp.clear();
																					for(int i = 3 ;i >=1 ; i--){
																						int j;
																						tmp = tmp + a[i][j++];
																						cout << tmp;
																						if(tmp == dic[10]){
																							cout << " Found " << ++total<< endl;
																							tmp.clear();
																							for(int i = 1 ;i >=0 ; i--){
																								tmp = tmp + a[i][i];
																								cout << tmp;
																								if(tmp == dic[3]){
																									cout << " Found " << ++total<< endl;
																									tmp.clear();
																									for(int i = 2 ;i <=3 ; i++){
																										tmp = tmp + a[0][i];
																										cout << tmp;
																										if(tmp == dic[0]){
																											cout << " Found " << ++total<< endl;
																											tmp.clear();
																											cout << endl << "Total = " << total;
																										} cout << endl;
																									}
																								} cout << endl;
																							}
																						} cout << endl;
																					}
																				} cout << endl;
																			}
																		} cout << endl;
																	}	
																} cout << endl;
															}	
														} cout << endl;
													}
												} cout << endl;
											}
										} cout << endl;
									}
								} cout << endl;
							}
						} cout << endl;
					}
				} cout << endl;
			}
		} cout << endl;
	}
	return 0;			
}
