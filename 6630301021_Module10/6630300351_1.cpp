#include <iostream>
#include <string>
using namespace std;

struct record* adj[6];

struct record{
    int value;
    struct record* next;
};

void showAdj(){
    cout << "ADJACENCY LIST" << endl;
    for(int i=0;i<6;i++){
        cout << "#" << i << " : ";
        struct record* p;
        p=adj[i];
        while(p!=NULL){
            cout << p->value << " ";
            p=p->next;
        }
        cout << endl;
    }
    cout << endl;
}

void InputAdj(){
    cout << endl;
    string str;
    for(int i=0;i<6;i++){
        adj[i]=NULL;
        cout << "Enter #" << i << " : ";
        while(cin>>str){
            if(str=="-1"){
                break;
            }else{
                if(adj[i]==NULL){
                    adj[i]=new struct record;
                    adj[i]->value=stoi(str);
                    adj[i]->next=NULL;
                }else{
                    struct record* p;
                    p=adj[i];
                    while(p->next!=NULL){
                        p=p->next;
                    }
                    p->next=new struct record;
                    p->next->value=stoi(str);
                    p->next->next=NULL;
                }
            }
        }
    }
    cout << endl;
    showAdj();
}

void Selfloop(){
    cout << endl;
    for(int i=0;i<6;i++){
        struct record* p;
        p=adj[i];
        while(p!=NULL){
            if(i==p->value){
                cout << "Selfloop : " << i << endl;
            }
            p=p->next;
        }
    }
    cout << endl;
}

char menu(){
    char ch;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Input adjacency list" << endl;
    cout << "2) Show self loop from adjacency list" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose >  ";
    cin >> ch;
    return ch;
}

int main(){
    char ch;
    int num;

    while(true){
        ch=menu();
        if(ch=='1'){
            InputAdj();
        }else if(ch=='2'){
            Selfloop();
        }else if(ch=='3'){
            break;
        }
    }
    return 0;
    
}

/*
#0 : 1 3 -1
#1 : 4 -1
#2 : 2 4 5 -1
#3 : 1 -1
#4 : 3 -1
#5 : 5 -1
*/