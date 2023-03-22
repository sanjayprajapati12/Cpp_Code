#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void addEdge(int a,int b,vector<int> graph[]){
    graph[a].pb(b);
}

bool checkCycle(int v , vector<bool> visited , vector<bool> DFSvisited , vector<int> graph[]){
    visited[v] = true;
    DFSvisited[v] = true;
    for(auto child : graph[v]){
        if(!visited[child]){
            if(checkCycle(child,visited,DFSvisited,graph)) return true;
        }
        else if(DFSvisited[child]) return true;
    }
    DFSvisited[v] = false;
    return false;
}

bool isCycle(int n , vector<int> graph[]){
    vector<bool> visited(n+1,0);
    vector<bool> DFSvisited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(checkCycle(i,visited,DFSvisited,graph)) return true;
        }
    }
    return false;
}

int32_t main(){
    int n; // number of nodes
    int m; // no of edges
    cin>>n>>m;
    vector<int> graph[n+1];  

    // make graph
    while(m--){
        int a,b;
        cin>>a>>b;
        addEdge(a,b,graph);
    }
    
    if(isCycle(n,graph)) cout<<"There is a cycle "<<endl;
    else cout<<"There is no cycle "<<endl;

    return 0;
}  