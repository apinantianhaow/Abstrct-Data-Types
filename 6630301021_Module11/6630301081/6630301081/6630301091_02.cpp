#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> adj;
int Time=0;
int pass[6];
int pred[6];
int d[6];
int f[6];
void dfs_visit(int u){
    d[u]=Time++;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(pass[v]==0){
            pred[v]=u;
            dfs_visit(v);
        }
    }
    pass[u]=1;
    f[u]=Time++;
}
void dfs(int data){
    for(int i=0;i<6;i++){
        pass[i]=0;
        pred[i]=d[i]=f[i]=-1;
    }
    for(int i=0;i<6;i++){
        if(pass[i]==0){
            dfs_visit(i);
        }
    }
}


int main(){
    bool check=true;
    int n,m,u,v;
    while(check){
cout<<"========================"<<endl;
cout<<"           MENU         "<<endl;
cout<<"========================"<<endl;
cout<<"1. Input Graph"<<endl;
cout<<"2. DFS"<<endl;
cout<<"3. Exit"<<endl;
cout<<"Please choose >";
int choose; 
cin>>choose;
    switch (choose)
    {
    case 1:
       cout<<"Enter Vertex and Edge : ";cin>>n>>m;
       adj.resize(n);
       cout<<"u and v"<<endl;
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
        break;
    case 2:
        cout<<"Enter source : ";int data;cin>>data;
        dfs(data);
        cout<<"pred"<<endl;
        for(int i=0;i<n;i++){
            cout<<i<<" | ";
            if(pred[i]==-1){
                cout<<i<<endl;
            }
            else{
                cout<<pred[i]<<endl;
            }
        }
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