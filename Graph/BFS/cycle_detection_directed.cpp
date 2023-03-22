#include<bits/stdc++.h>
using namespace std;
//  use of kahn's algorithm -topology sort
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
    for(int i=1 ;i<=n;i++){
        for(auto it:graph[i])
            indegree[it]++;
    }

    queue<int> q;
    for(int i=1 ;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
 
    int cnt = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        cnt++;
        for (int u : graph[v]) {
            indegree[u]--;
            if(indegree[u]==0)
                q.push(u);
        }
    }
    
    //  if there is no cycle then topology sort is done . so cnt==N
    if(cnt==n)cout<<"There is no cycle"<<endl;
    else cout<<"There is cycle"<<endl;
    
return 0;
}  