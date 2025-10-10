//6630301021 Aphinan Thianhao

#include <iostream>
#include <vector>
#include <string>
#include<list>
using namespace std;

vector<int> adj[100];
vector<string> des = {"Undershorts", "Pants", "Belt", "Shirt", "Tie", "Jacket", "Sock", "Shoes", "Watch"};

bool pass[100];
int d[100];
int f[100];
int pred[100];
int Time = 0;
int vertex, edge;

list<int> l;
bool passofmax[100];

void Digraph(){
    cout << "Enter Vertex and Edge : ";
    cin >> vertex >> edge;
    cout << "Enter u and v :" << endl;
    int u,v;
    for(int i = 0 ; i < edge ; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << endl << "Directed graph" << endl;
    for(int i = 0 ; i < vertex ; i++){
        cout << "#" << i << " : ";
        for(int j = 0 ; j < adj[i].size() ; j++){
            if(j == adj[i].size() - 1){
                cout << adj[i][j];
            }else{
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void DFS_Visit(int u){
    pass[u] = true;
    d[u] = ++Time;
    for(int i = 0 ; i < adj[u].size() ; i++){
        if(pass[adj[u][i]] == false){
            pred[adj[u][i]] = u;
            DFS_Visit(adj[u][i]);
        }
    }
    f[u] = ++Time;
}

void DFS(){
    int u = 0;
    for(int i = 0 ; i < vertex ; i++){
        pass[i] = false;
        d[i] = -1;
        f[i] = -1;
        pred[i] = -1;
    }
    pred[u] = u;
    DFS_Visit(u);
    for(int i = 0 ; i < vertex ; i++){
        if(pass[i] == false){
            pred[i] = i;
            DFS_Visit(i);
        }
    }
}

void Topological_Sort(){
    for(int i = 0 ; i < vertex ; i++){
        passofmax[i] = false;
    }
    l.clear();
    for(int i = 0 ; i < vertex ; i++){
        int Max = -1;
        int index = -1;
        for(int j = 0 ; j < vertex ; j++){
            if(f[j] > Max && !passofmax[j]){
                Max = f[j];
                index = j;
            }
        }
        passofmax[index] = true;
        l.push_back(index);
    }
    int no = 0;
    for(auto i : l){
        cout << endl;
        cout << no + 1 << ". " << des[i];
        no++;
    }
    cout << endl;
}

int main(){
    int choose;
    while(true){
        cout << "===================" << endl;
        cout << "     MENU          " << endl;
        cout << "===================" << endl;
        cout << "   1) Input graph" << endl;
        cout << "   2) DFS" << endl;
        cout << "   3) Topological sort" << endl;
        cout << "   4) Exit" << endl;
        cout << "   Please choose > ";
        cin >> choose;

        switch (choose){
            case 1:{
                Digraph();
                break;
            }
            case 2:{
                if(vertex > 0){
                    DFS();
                    cout << endl;
                } else {
                    cout << endl << "No Data!!!" << endl << endl;
                }
                break;
            }
            case 3:{
                Topological_Sort();
                cout << endl;
                break;
            }
            case 4:{
                cout << endl;
                exit(0);
                break;
            }
        }
    }
    return 0;
}