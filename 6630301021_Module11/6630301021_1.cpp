//6630301021 Aphinan Thianhao

#include <iostream>
#include <vector>
using namespace std;

void Digraph(){
    int n, m, u, v;
    cout << "Enter Vertex and Edge : ";
    cin >> n >> m;
    vector <vector<int>> adj(n);
    cout << "Enter u and v :" << endl;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << endl << "Directed graph" << endl;
    for (int i = 0 ; i < n ; i++){
        cout << "#" << i << " : ";
        for (int j = 0 ; j < adj[i].size() ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Undigraph(){
    int n, m, u, v;
    cout << "Enter Vertex and Edge : ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    cout << "Enter u and v :" << endl;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << endl << "Undirected graph" << endl;
    for (int i = 0 ; i < n ; i++){
        cout << "#" << i << " : ";
        for (int j = 0 ; j < adj[i].size() ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
	int choose;
    while (true) {
        cout << "===================" << endl;
        cout << "     MENU          " << endl;
        cout << "===================" << endl;
        cout << "     1. Digraph" << endl;
        cout << "     2. Undigraph" << endl;
        cout << "     3. Exit" << endl;
        cout << "     Please choose > ";
        cin >> choose;

        switch (choose) {
        case 1:{
        	Digraph();
			break;
		}
        case 2:{
        	Undigraph();
			break;
		}
        case 3:
        	exit(0);
			break;
    	}
	}
	return 0;
}

