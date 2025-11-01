#include <iostream>
using namespace std;

struct record {
    int value;
    struct record* next;
};

struct record* adj[8];
int pass[8];
int d[8];
int pred[8];

struct record *insert(struct record* head, int data) {
    if (!head) {
        head = new record{data, NULL};
        return head;
    }
    record* p = head;
    while (p->next) p = p->next;
    p->next = new record{data, NULL};
    return head;
}

void printList(struct record* head) {
    for (record* p = head; p; p = p->next) cout << p->value << " ";
}

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

void BFS() {
    cout << endl;
    for (int i = 0; i < 8; ++i) {
        pass[i] = 0;
        d[i]    = 0;
        pred[i] = -1;
    }

    int q[128]; int front = 0, back = 0;
    q[back++] = 1;          
    pass[1] = 1;
    d[1]    = 0;
    pred[1] = 1;

    while (front < back) {
        int u = q[front++];
        struct record *node = adj[u];
        while (node) {
            int v = node->value;
            if (!pass[v]) {
                pass[v] = 1;
                d[v]    = d[u] + 1;
                pred[v] = u;
                q[back++] = v;
            }
            node = node->next;
        }
    }

    cout << "node | d | pred" << endl;
    cout << "=============" << endl;
    for (int i = 0 ; i < 8 ; ++i) {
        cout << i << " | " << d[i] << " | " << pred[i] << endl;
    }
    cout << endl;
}

void Searchpath() {
    cout << endl << "Enter end point : ";
    int target; cin >> target;

    if (target < 0 || target >= 8) {
        cout << "Invalid node" << endl << endl;
        return;
    }
    if (!pass[target]) {
        cout << "No path (run BFS first or node unreachable)" << endl << endl;
        return;
    }

    int tmp[16]; int cnt = 0;
    int pos = target;
    while (true) {
        tmp[cnt++] = pos;
        if (pos == 1) break;      
        pos = pred[pos];
        if (pos == -1) break;   
    }

    cout << "Path = ";
    for (int i = cnt - 1 ; i > 0 ; --i) {
        cout << "(" << tmp[i] << "," << tmp[i - 1] << ")";
        if (i - 1 > 0) cout << " , ";
    }
    cout << endl;
    cout << "Distance = " << d[target] << endl << endl;
}

int main() {
    int choice;

    for (int i = 0 ; i < 8 ; ++i) {
        adj[i]  = NULL;
        pass[i] = 0;
        d[i]    = 0;
        pred[i] = -1;
    }

    while (true) {
        cout << "===========MENU==========" << endl;
        cout << "1) Input adjacency list" << endl;
        cout << "2) BFS" << endl;
        cout << "3) Search path" << endl;
        cout << "4) Exit" << endl;
        cout << "Please choose > ";
        cin >> choice;

        switch (choice) {
            case 1: 
                InputAdj(); 
                break;
            case 2: 
                BFS(); 
                break;
            case 3: 
                Searchpath(); 
                break;
            case 4:     
                exit(0);
                break;
        }
    }
    return 0;
}