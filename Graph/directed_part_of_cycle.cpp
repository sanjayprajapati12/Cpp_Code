#include<bits/stdc++.h>
using namespace std;

// for undirected graph refer below link
// https://www.geeksforgeeks.org/print-all-the-cycles-in-an-undirected-graph/

// If cntcycle[i]>0 for any i that means i is in some cycle

#define pb push_back

void addEdge(int a,int b,vector<int> graph[]){
    graph[a].pb(b);
}

int32_t main(){

    int n; // number of nodes
    int m; // no of edges
    cin>>n>>m;
    vector<int> graph[n];  

    // make graph
    while(m--){
        int a,b;
        cin>>a>>b;
        addEdge(a,b,graph);
    }
    vector<int> col(n,1);
    vector<int> parent(n,-1);
    vector<int> cntcycle(n,0);
    vector<int> prefixorder;
    function<void(int,int)> dfs = [&](int node, int par){
        parent[node] = par;
        col[node] = 2;
        // cout<<"node "<<node<<endl;
        // cout<<" par " <<par<<endl;
        for (auto v : graph[node])  {
            if (col[v] == 1){
                dfs(v, node);
            }
            else if (col[v] == 2){
                // cout<<" i node "<<node<<endl;
                // cout<<" i par "<<parent[v]<<endl;
                cntcycle[node]++;
                if(parent[v]!=-1){
                    cntcycle[parent[v]]--;
                }
            }
        }
        col[node] = 3;
        
        // topo sort u can say 
        prefixorder.push_back(node);
    };
    
    for(int i=0 ; i<n ; i++){
        if(col[i]==1){
            dfs(i,-1);
        }
    }

    for(auto &x:prefixorder){
        // cout<<x<<" ";
        cntcycle[parent[x]] += cntcycle[x];
    }
    // cout<<endl;

    // for(int i=0 ; i<n ; i++){
    //     cout<<cntcycle[i]<<" ";
    // }
    // cout<<endl;
    

    for(int i=0 ; i<n ; i++){
        if(cntcycle[i]>0){
            cout<<i<<" ";
        }
        // cout<<cntcycle[i]<<" ";
    }
    cout<<endl;
    
 return 0;  
}  

    // int timer = 0;
    // std::function<void(int)> dfs = [&](int x) {
    //     vis[x] = timer++;
    //     for (auto y : adj[x]) {
    //         if (y == parent[x]) {
    //             continue;
    //         }
    //         if (vis[y] == -1) {
    //             parent[y] = x;
    //             dfs(y);
    //         } else if (vis[x] > vis[y]) {
    //             for (int i = x; i != y; i = parent[i]) {
    //                 cyc[i] = true;
    //             }
    //             cyc[y] = true;
    //         }
    //     }
    // };