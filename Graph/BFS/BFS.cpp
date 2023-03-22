#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void addEdge(int a,int b,vector<int> graph[]){
        graph[a].pb(b);
        graph[b].pb(a);
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

    queue<int> q;
    vector<bool> visited(n+1,0);
    vector<int> d(n+1,0);  // store distance
    vector<int> p(n+1);  // store parent

    // BFS
    int s=1;  // source vertex which is given;
    q.push(s);
    visited[s] = true;
    p[s] = -1;  // parent of source doesn't exist
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : graph[v]){
            if (!visited[u]){
                q.push(u);
                visited[u] = true;
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
        cout<<v<<" -> ";
    }

    cout<<endl;
    cout<<endl;

    // distance
    cout<<"Level : "<<endl;
    for(int i=1; i<=n ;i++) cout<<i<<" "<<d[i]<<endl;

    cout<<endl;
    // parent 
    cout<<"Parent: "<<endl;
    for(int i=1; i<=n ;i++) cout<<i<<" "<<p[i]<<endl;
    
    return 0;
}  