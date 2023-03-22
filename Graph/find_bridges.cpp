#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 10e5


void DFS(int v,int p,vector<int> graph[],bool visited[],vector<int> &in , vector<int> &low , int &timer , vector<pair<int,int>> &bridge){
    visited[v] = true;
    in[v] = low[v] = timer++;

    for(auto child : graph[v]){
        if(child==p) continue ;
        if(visited[child]){
            // this is back edge
            low[v] = min(low[v] , in[child]); 
        }
        else{
            // this is forward edge
            DFS(child,v,graph,visited,in,low,timer,bridge);
            if(low[child]>in[v]){
                bridge.pb({v,child});
            }
            low[v] = min (low[v],low[child]);
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
    
    vector<int> in(n+1,-1);
    vector<int> low(n+1,-1);

    bool visited[n+1] = {false};
    vector<pair<int,int>> bridge;
    int timer = 0 ;

    // here we take 1 as vertex 
    for(int i=1 ;i<=n;i++){
        if(!visited[i]){
            DFS(i,-1,graph,visited,in,low,timer,bridge);
        }
    }

    // Bridge 
    cout<<"Bridge: "<<endl;
    for(auto &x:bridge) 
        cout<<x.first<<" "<<x.second<<endl;

    return 0;
}