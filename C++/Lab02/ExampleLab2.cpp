#include<stdio.h>
#include<iostream>
using namespace std;
int a[10];
void showmenu(){
	cout<<"========MENU========"<<endl;
	cout<<"1) Insert"<<endl;
	cout<<"2) Delete"<<endl;
	cout<<"3) Print"<<endl;
	cout<<"4) Find"<<endl;
	cout<<"5) Exit"<<endl;
	cout<<"Please choose> ";
}
void print(int size,int choose){
	if(choose == 3){
		cout<<"Print :";
	}else{
		cout<<"Output :";
	}
	for(int i=0;i<=size;i++){
		cout<<" "<<a[i];
	}
	cout<<endl<<endl;
}

void sort(int size){
	int one,two;
	if(size > 0){
		for(int i=0;i<=size-1;i++){
			one = a[i];
			two = a[i+1];
			if(one > two){
				a[i] = two;
				a[i+1] = one;
			}
		}
	}
}

int insert(int size,int choose){
	int data;
	cout<<"Enter : ";
	cin>>data;
	if(++size <= 9){
		for(int i = 9;i>=0;i--){
			a[i] = a[i-1];
		}
		a[0] = data;
		sort(size);
		print(size,choose);
	}else{
		cout<<"List Full"<<endl<<endl;
		size = 9;
	}
	return size;
}

void find(int size){
	int data,find=0;
	cout<<"Find : ";
	cin>>data;
	for(int i=0;i<=size;i++){
		if(a[i] == data){
			find=1;
		}
	}
	if(find == 0){
		cout<<"Not Found";
	}else{
		cout<<"Found";
	}
	cout<<endl<<endl;
}

int del(int size){
	int data,find=0;
	if(size == -1){
		cout<<"Empty List";
	}else{
		cout<<"Enter : ";
		cin>>data;
		for(int i=0;i<=size;i++){
			if(a[i] == data){
				for(int j=i;j<=size-1;j++){
					a[j] = a[j+1];
				}
				++find;
			}
		}
		if(find==0){
			cout<<"Not Found";
		}else{
			size = size-find;
			cout<<"Success";
		}
	}
	cout<<endl<<endl;
	return size;
}

int main(){
	int choose,size=-1;
	while(1){
		showmenu();
		cin>>choose;
		switch(choose){
			case 1:
				size=insert(size,choose);
				break;
			case 2:
				size=del(size);
				break;
			case 3:
				print(size,choose);
				break;
			case 4:
				find(size);
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"No choice!"<<endl;
				break;
		}
	}
	return 0;
}
