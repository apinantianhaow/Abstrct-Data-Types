#include <iostream>

using namespace std;

struct record{
	int value;
	struct record *next;
};

struct frontback{
	struct record *front;
	struct record *back;
};

struct frontback Enqueue(struct record *front,struct record *back,int data);
struct frontback Dequeue(struct record *front,struct record *back);
int Josephus(int n,int m,struct frontback store);


int main(){
	int i,n,m;
	struct record *front = NULL,*back = NULL;
	struct frontback store;

	cout << "Input N : ";
	cin >> n;
	cout << "Input M : ";
	cin >> m;

	for(i = 1;i <= n;i++){
		store = Enqueue(front,back,i);
		front = store.front;
		back = store.back;
	}
	cout << "Winner is = " << Josephus(n,m,store);
	return 0;
}


struct frontback Enqueue(struct record *front,struct record *back,int data){
	struct record *q;
	struct frontback store;
	if(front == NULL && back == NULL){
		front = new struct record;
		front -> value = data;
		front -> next = NULL;
		back = front;
	}else{
		q = new struct record;
		q -> value = data;
		q -> next = front;
		back -> next = q;
		back = q;
	}
	store.front = front;
	store.back = back;
	return store;
}

struct frontback Dequeue(struct record *front,struct record *back){
	struct record *tmp;
	struct frontback store;

	if(front == NULL){
		cout << "Empty! Cant Dequeue"<<endl;
	}else{
		tmp = front;
		front = front -> next;
		back -> next = front;
		if(front == NULL){
			store.front = NULL;
			store.back = NULL;
			return store;
		}
		delete(tmp);
	}
	store.front = front;
	store.back = back;

	return store;
}

int Josephus(int n,int m,struct frontback store){
	int count_m = 0,count_del = 0;
	struct record *front = NULL,*back = NULL;
	front = store.front;
	back = store.back;
	while(count_del != n - 1){
		if(count_m == m){
			count_del++;
			store = Dequeue(front,back);
			front = store.front;
			back = store.back;
			count_m = 0;
		}else{
			count_m++;
			front = front -> next;
			back = back -> next;
		}
	}

	return front -> value;
}
