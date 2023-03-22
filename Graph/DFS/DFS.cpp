#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 10e5

vector<int> p(N+1);  // store parent

void DFS(int v,vector<int> graph[],bool visited[]){
    visited[v] = true;
    cout<<v<<" -> ";
    for(auto child : graph[v]){
        if(!visited[child]){
            p[child] = v;
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

    while(m--){
        int a,b;
        cin>>a>>b;
        addEdge(a,b,graph);
    }
    
    bool visited[n+1] = {false};
   
    // here we take 1 as vertex 
    for(int i=1 ;i<=n;i++){
        if(!visited[i]){
            p[i]=-1;
            DFS(i,graph,visited);
        }
    }
    cout<<endl;
    cout<<endl;

    cout<<endl;
    // parent 
    cout<<"Parent: "<<endl;
    for(int i=1; i<=n ;i++) cout<<i<<" "<<p[i]<<endl;

    return 0;
}