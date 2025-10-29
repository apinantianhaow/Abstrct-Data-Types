//6630301021 Aphinan Thianhao

#include <iostream>
#include <string>
using namespace std;

struct record *adj[6];

struct record{
    int value;
    struct record *next;
};

void showAdj(){
    cout << "ADJACENCY LIST" << endl;
    for(int i = 0 ; i < 6 ; i++){
        cout << "#" << i << " : ";
        struct record *p = adj[i];
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
    for(int i = 0 ; i < 6 ; i++){
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
                    struct record *p = adj[i];
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

void Selfloop(){
    cout << endl;
    for(int i = 0 ; i < 6 ; i++){
        struct record *p = adj[i];
        while(p != NULL){
            if(i == p->value){
                cout << "Selfloop : " << i << endl;
            }
            p = p->next;
        }
    }
    cout << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "===========MENU==========" << endl;
        cout << "1) Input adjacency list" << endl;
        cout << "2) Show self loop from adjacency list" << endl;
        cout << "3) Exit" << endl;
        cout << "Please choose > ";
        cin >> choice;

        switch (choice) {
            case 1:{
            	InputAdj();
				break;
			}
            case 2:{
            	Selfloop();
				break;
			}
            case 3:{
                exit(0);
				break;
			}
        }
    }
    return 0;
}
