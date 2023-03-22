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


    int c=0;
    // BFS
    for(int i=1 ;i<=n ; i++){
        if(!visited[i]){
            c++;
            q.push(i);
            visited[i] = true;
            p[i] = -1;  // parent of source doesn't exist
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : graph[v]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        q.push(u);
                        d[u] = d[v] + 1;
                        p[u] = v;
                    }
                }
            }
        }
    }
    cout<<c<<endl;
    
 return 0;
}  