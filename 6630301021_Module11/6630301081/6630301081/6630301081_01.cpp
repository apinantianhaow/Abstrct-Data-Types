#include<iostream>
#include<vector>
using namespace std;

int main(){
     vector<vector<int>> adj;
    bool check=true;
    int n,m,u,v;
    while(check){
cout<<"========================"<<endl;
cout<<"           MENU         "<<endl;
cout<<"========================"<<endl;
cout<<"1. Digraph"<<endl;
cout<<"2. Undigraph"<<endl;
cout<<"3. Exit"<<endl;
cout<<"Please choose >";
int choose; 
cin>>choose;
    switch (choose)
    {
    case 1:
        cout<<"Enter Vertex and Edge : ";cin>>n>>m;
        adj.resize(n);
        cout<<"Enter u and v :"<<endl;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        cout<<endl;
        cout<<"Directed graph"<<endl;
        for(int i=0;i<n;i++){
            cout<<"#"<<i<<" : ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    case 2:
        cout<<"Enter Vertex and Edge : ";cin>>n>>m;
        adj.resize(n);
        cout<<"Enter u and v :"<<endl;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<endl;
        cout<<"Undirected graph"<<endl;
        for(int i=0;i<n;i++){
            cout<<"#"<<i<<" : ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        break;
    case 3:
        check=false;
        break;
    default:
        cout<<"No ans"<<endl;
        break;
    }
}

}