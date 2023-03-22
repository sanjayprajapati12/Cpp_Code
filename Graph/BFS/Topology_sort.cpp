#include<bits/stdc++.h>
using namespace std;
// kahn's algorithm
#define pb push_back

void addEdge(int a,int b,vector<int> graph[]){
        graph[a].pb(b);
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

    // find indegree
    vector<int> indegree(n+1,0);
    for(int i=1 ; i<=n ; i++){
        for(auto it:graph[i])
            indegree[it]++;
    }

    queue<int> q;
    for(int i=1 ;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int v = q.front();
        cout<<v<<" ";
        q.pop();
        for(int u : graph[v]){
            indegree[u]--;
            if(indegree[u]==0)
                q.push(u);
        }
    }
    
   return 0;
}  