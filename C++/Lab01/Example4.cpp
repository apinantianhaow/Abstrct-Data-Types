#include<iostream>
using namespace std;

int main(){
	char puzzle[4][4] = {
	{'T','H','I','S'},
	{'W','A','T','S'},
	{'O','A','H','G'},
	{'F','G','D','T'}};
	
	string temp="",dic[11] = {"IS","THIS","HIS","AT","HI","IT","TWO","OF","THAT","HAT","FAT"};
	int i,j=0,total=0;
	
	for(i=2;i<=3;i++){
		temp=temp + puzzle[0][i];
		cout<<temp;
		if(temp==dic[0]){
			cout<<" Found "<<++total<<endl;
			temp.clear();
			for(i=0;i<=3;i++){
				temp=temp + puzzle[0][i];
				cout<<temp;
				if(temp==dic[1]){
					cout<<" Found "<<++total<<endl;
					temp.clear();
					for(i=1;i<=3;i++){
						temp=temp + puzzle[0][i];
						cout<<temp;
						if(temp==dic[2]){
							cout<<" Found "<<++total<<endl;
							temp.clear();
							for(i=1;i<=2;i++){
								temp=temp + puzzle[1][i];
								cout<<temp;
								if(temp==dic[3]){
									cout<<" Found "<<++total<<endl;
									temp.clear();
									for(i=1;i<=2;i++){
										temp=temp + puzzle[0][i];
										cout<<temp;
										if(temp==dic[4]){
											cout<<" Found "<<++total<<endl;
											temp.clear();
											for(i=0;i<=1;i++){
												temp=temp + puzzle[i][2];
												cout<<temp;
												if(temp==dic[5]){
													cout<<" Found "<<++total<<endl;
													temp.clear();
													for(i=0;i<=2;i++){
														temp=temp + puzzle[i][0];
														cout<<temp;
														if(temp==dic[6]){
															cout<<" Found "<<++total<<endl;
															temp.clear();
															for(i=2;i<=3;i++){
																temp=temp + puzzle[i][0];
																cout<<temp;
																if(temp==dic[7]){
																	cout<<" Found "<<++total<<endl;
																	temp.clear();
																	for(i=3;i>=0;i--){
																		temp=temp + puzzle[i][i];
																		cout<<temp;
																		if(temp==dic[8]){
																			cout<<" Found "<<++total<<endl;
																			temp.clear();
																			for(i=2;i>=0;i--){
																				temp=temp + puzzle[i][i];
																				cout<<temp;
																				if(temp==dic[9]){
																					cout<<" Found "<<++total<<endl;
																					temp.clear();
																					for(i=3;i>=0;i--){
																						temp=temp + puzzle[i][j++];
																						cout<<temp;
																						if(temp==dic[10]){
																							cout<<" Found "<<++total<<endl;
																							temp.clear();
																							cout<<"Total = "<<total;
																							exit(0);
																						}
																						cout<<endl;
																					}
																				}
																				cout<<endl;
																			}
																		}
																		cout<<endl;
																	}
																}
																cout<<endl;
															}
														}
														cout<<endl;
													}
												}
												cout<<endl;
											}
										}
										cout<<endl;
									}
								}
								cout<<endl;
							}
						}
						cout<<endl;
					}
				}
				cout<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
