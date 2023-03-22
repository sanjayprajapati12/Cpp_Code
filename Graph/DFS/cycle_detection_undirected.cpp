#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 10e5

vector<int> p(N+1,0);  // store parent

void addEdge(int a,int b,vector<int> graph[]){
        graph[a].pb(b);
        graph[b].pb(a);
}

bool checkCycle(int v ,int parent , vector<bool> visited , vector<int> graph[]){
    visited[v] = true;
    for(auto child : graph[v]){
        if(!visited[child]){
            if(checkCycle(child,v,visited,graph)) return true;
        }
        else if(child!=parent && visited[child]) return true;
    }
    return false;
}

bool isCycle(int n , vector<int> graph[]){
    vector<bool> visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            p[i]=-1;
            if(checkCycle(i,-1,visited,graph)) return true;
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