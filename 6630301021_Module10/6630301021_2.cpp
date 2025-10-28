//6630301021 Aphinan Thianhao

#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct record *adj[8];
queue<int> q;
stack<int> s;
int pass[8];
int d[8];
int pred[8];

struct record{
    int value;
    struct record *next;
};

void showAdj(){
    cout << "ADJACENCY LIST" << endl;
    for(int i = 0 ; i < 8 ; i++){
        cout << "#" << i << " : ";
        struct record *p;
        p = adj[i];
        while(p != NULL){
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
    cout << endl;
}

void InputAdj(){
    cout << endl;
    string str;
    for(int i = 0 ; i < 8 ; i++){
        adj[i] = NULL;
        cout << "Enter #" << i << " : ";
        while(cin >> str){
            if(str == "-1"){
                break;
            }else{
                if(adj[i] == NULL){
                    adj[i] = new struct record;
                    adj[i]->value = stoi(str);
                    adj[i]->next = NULL;
                }else{
                    struct record *p;
                    p = adj[i];
                    while(p->next != NULL){
                        p = p->next;
                    }
                    p->next = new struct record;
                    p->next->value = stoi(str);
                    p->next->next = NULL;
                }
            }
        }
    }
    cout << endl;
    showAdj();
}

void BFS(){
	cout << endl;
    for(int i = 0 ; i < 8 ; i++){
        pass[i] = 0;
        d[i] = 0;
        pred[i] = 0;
    }
    q.push(1);
    pass[1] = 1;
    d[1] = 0;
    pred[1] = 1;
    while(q.size() != 0){
        int u;
        u = q.front();
        struct record *node;
        node = adj[u];
        while(node != NULL){
            int v;
            v = node->value;
            if(pass[v] == 0){
                pass[v] = 1;
                d[v] = d[u] + 1;
                pred[v] = u;
                q.push(v);
            }
            node = node->next;
        }
        q.pop();
    }

    cout << "node | d | pred" << endl;
    cout << "=============" << endl;
    for(int i = 0 ; i < 8 ; i++){
        cout << i << " | " << d[i] << " | " << pred[i] << endl;
    }
    cout << endl;
}

void LoopPred(int num){
    s.push(num);
    if(d[num] != 0){
        LoopPred(pred[num]);
    }
    return;
}

void Searchpath(){
    cout << endl;
    int num;
    cout << "Enter end point : ";
    cin >> num;
    cout << "Path = ";
    LoopPred(num);
    int re = 1;
    while(s.size() != 0){
        if(re == d[num]){
            cout << "(";
            cout << s.top();
            cout << ",";
            s.pop();
            cout << s.top();
            cout << ")";
            s.pop();
        }else{
            cout << "(";
            cout << s.top();
            cout << ",";
            s.pop();
            cout << s.top();
            cout << ")";
            cout << ",";
            re++;
        }
    }
    cout << endl;
    cout << "Distance = " << d[num] << endl;
    cout << endl;
}

int main(){
	int choice;
	
    while (true) {
        cout << "===========MENU==========" << endl;
        cout << "1) Input adjacency list" << endl;
        cout << "2) BFS" << endl;
        cout << "3) Search path" << endl;
        cout << "4) Exit" << endl;
        cout << "Please choose > ";
        cin >> choice;

        switch(choice) {
            case 1:{
            	InputAdj();
				break;
			}
            case 2:{
            	BFS();
				break;
			}
            case 3:{
            	Searchpath();
				break;
			}
            case 4:{
            	exit(0); 
				break;
			}
        }
    }
    return 0;
}

