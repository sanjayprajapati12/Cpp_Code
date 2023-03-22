#include<bits/stdc++.h>
using namespace std;

#define pb push_back 

void DFS(int v,vector<int> graph[],bool visited[]){
    visited[v] = 1;
    for(int i=0 ;i<graph[v].size();i++){
        int child = graph[v][i];
        if(!visited[child]){
            DFS(child,graph,visited);
        }
    }
}

void addEdge(int a,int b,vector<int> graph[]){
        graph[a].pb(b);
        graph[b].pb(a);
}
 
int32_t main(){
    
    // n--> nodes , m-->edges
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    
    bool visited[n+1] = {};
    while(m--){
        int a,b;
        cin>>a>>b;
        addEdge(a,b,graph);
    }

    // count connected component 
    int c=0;
    for(int i=1 ;i<=n;i++){
        if(!visited[i]){
            DFS(i,graph,visited);
            c++;
        }
    }

    cout<<c<<endl;
    if(c>1)
        cout<<"Graph is not connected (it means that graph has more than one component)"<<endl;
    else
        cout<<"Graph is connected (it means that graph has only one component)"<<endl;
    
    return 0;
}