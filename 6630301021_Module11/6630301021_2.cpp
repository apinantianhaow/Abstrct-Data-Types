//6630301021 Aphinan Thianhao

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[200];
int Time = 0;
int n, m;
int pass[200];   
int pred[200];
int d[200];     
int f[200];  

void inputGraph(){
    cout << "Enter Vertex and Edge : ";
    cin >> n >> m;
    cout << "Enter u and v : " << endl;
    int u, v;
    for(int i = 0 ; i < m ; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << endl << endl;
    cout << "Directed graph" << endl;
    for(int i = 0 ; i < n ; i++){
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
    d[u] = Time++;
    for(int i = 0 ; i < adj[u].size() ; i++){
        if(pass[adj[u][i]] == false){
            pred[adj[u][i]] = u;
            DFS_Visit(adj[u][i]);
        }
    }
    pass[u] = true;
    f[u] = Time++;
}

void DFS(){
    int u;
    for(int i = 0 ; i < n ; i++){
        pass[i] = false;
        d[i] = -1;
        f[i] = -1;
        pred[i] = -1;
    }
    cout << "Enter source : ";
    cin >> u;
    pred[u] = u;
    DFS_Visit(u);
    for(int i = 0 ; i < n ; i++){
        if(pass[i] == false){
            pred[i] = i;
            DFS_Visit(i);
        }
    }
    cout << "Output" << endl;
    cout << "Pred" << endl;
    for(int i = 0 ; i < n ; i++){
        cout << i << " | " << pred[i] << endl;
    }
    cout << endl;
}

int main() {
    int data, choose;

    while (true) {
        cout << "================================" << endl;
        cout << "            MENU                " << endl;
        cout << "================================" << endl;
        cout << "   1. Input Graph" << endl;
        cout << "   2. DFS" << endl;
        cout << "   3. Exit" << endl;
        cout << "Please choose > ";
        cin >> choose;

        switch (choose) {
            case 1:{
                inputGraph();                
                break;
            }
            case 2:{
                DFS();
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
