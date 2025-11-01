#include <iostream>
using namespace std;
    
struct Node *adj[1000];

struct Node {               
    int value;
    struct Node *next;
};
           
int N = 0;               

void initGraph(int n) {
    N = n;
    if (N > 1000) N = 1000; 
    for (int i = 0; i < N; ++i) adj[i] = NULL;
}

void addEdge(int u, int v) {
    struct Node *newnode = new struct Node;
    newnode->value = v;
    newnode->next = NULL;

    if (adj[u] == NULL) {
        adj[u] = newnode;      
    } else {
        Node* p = adj[u];
        while (p->next != NULL)  
            p = p->next;
        p->next = newnode;      
    }
}

void printGraph(const char* title) {
    cout << endl << title << endl;
    for (int i = 0; i < N; ++i) {
        cout << "#" << i << " : ";
        for (struct Node *p = adj[i]; p != NULL; p = p->next) {
            cout << p->value << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void clearGraph() {
    for (int i = 0; i < N; ++i) {
        struct Node *p = adj[i];
        while(p) {
            struct Node *tmp = p;
            p = p->next;
            delete(tmp);
        }
        adj[i] = NULL;
    }
}

void Digraph() {
    int n, m, u, v;
    cout << "Enter Vertex and Edge : ";
    cin >> n >> m;
    initGraph(n);

    cout << "Enter u and v :" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;          
        if (0 <= u && u < N && 0 <= v && v < N)
            addEdge(u, v);
    }
    printGraph("Directed graph");
    clearGraph();
}

void Undigraph() {
    int n, m, u, v;
    cout << "Enter Vertex and Edge : ";
    cin >> n >> m;
    initGraph(n);

    cout << "Enter u and v :" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;          
        if (0 <= u && u < N && 0 <= v && v < N) {
            addEdge(u, v);
            addEdge(v, u);
        }
    }
    printGraph("Undirected graph");
    clearGraph();
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