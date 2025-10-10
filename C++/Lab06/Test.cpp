#include <iostream>
#include <cstdio>
using namespace std;
struct box;
typedef struct box *Stack;
typedef struct box Create;
struct box{
	char symbol;
	Stack next;
};
Stack head = NULL;
bool doubleQuoteOpening = true;
void insert(char symbol){
	Stack node;
	node = new Create;
	node->symbol = symbol;
	node->next = head->next;
	head->next = node;
}
void pop(){
	if(head->next != NULL){
		Stack tmp;
		tmp = head->next;
		head->next = head->next->next;
		delete(tmp);
	}
}
int checkError(char symbol){
	if(head != NULL){
		if(symbol == '"'){
			if(doubleQuoteOpening){
				insert(symbol);
				doubleQuoteOpening = false;
			}else{
				if(head->next->symbol == '"' && head->next != NULL){
					pop();
				}else{
					head->symbol=head->next->symbol;
					return 2;
				}
				doubleQuoteOpening = true;
			}
		}else{
			if(symbol=='}'||symbol==']'||symbol==')'){
				char tmpSymbol;
				switch(symbol){
					case '}':
						tmpSymbol = '{';
						break;
					case ']':
						tmpSymbol = '[';
						break;
					case ')':
						tmpSymbol = '(';
						break;
				}
				if(head->next->symbol == tmpSymbol && head->next != NULL){
					pop();
				}else{
					head->symbol=head->next->symbol;
					return 2;
				}
			}else if(symbol!='}'||symbol!=']'||symbol!=')'){
				insert(symbol);
			}	
		}
	}else{
		if(symbol=='}'||symbol==']'||symbol==')'){
			return 1;
		}else{
			if(symbol == '"'){
				doubleQuoteOpening = false;
			}
			head = new Create;
			head->next = NULL;
			insert(symbol);
		}
	}
	return 0;
}
int main(){
	char c;int status=0,error=0;
	cout<<"Input : ";
	do{
		c=getchar();
		if(c != ' ' && c != '\n'){
			status=checkError(c);
			if(status != 0){
				if(status == 1){
					cout<<"\""<<"Error : "<<c<<" No opening symbol."<<"\"";
					break;
				}else if(status == 2){
					cout<<"\""<<"Error : "<<head->symbol<<" Not the corresponding opening symbol."<<"\"";
					break;
				}
			}
		}
	}while(c != '\n');
	if(head != NULL){
		if(head->next != NULL && status == 0){
			cout<<"\""<<"Error : "<<head->next->symbol<<" Not Equal opening and closing symbol."<<"\"";
		}
	}
	return 0;
}
