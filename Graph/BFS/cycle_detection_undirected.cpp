#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void addEdge(int a,int b,vector<int> graph[]){
        graph[a].pb(b);
        graph[b].pb(a);
}

bool checkCycle(int s ,int n, vector<bool> visited , vector<int> graph[]){
    queue<int> q;
    vector<int> p(n+1);  // store parent
    q.push(s);
    visited[s] = true;
    p[s] = -1;  // parent of source doesn't exist
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
            if(p[v]!=u && visited[u]){
                return true;
            }
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
                p[u] = v;
            }
        }
    }
    return false;
}

bool isCycle(int n , vector<int> graph[]){
    vector<bool> visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(checkCycle(i,n,visited,graph)) return true;
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