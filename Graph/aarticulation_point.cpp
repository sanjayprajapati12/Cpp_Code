#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 10e5


void DFS(int v,int p,vector<int> graph[],bool visited[],vector<int> &in , vector<int> &low , int &timer , set<int> &AP){
    visited[v] = true;
    in[v] = low[v] = timer++;
    // children count 
    int children = 0;

    for(auto child : graph[v]){
        if(child==p) continue ;

        if(visited[child]){
            // this is back edge
            low[v] = min(low[v] , in[child]);  
        }
        else{
            // this is forward edge
            DFS(child,v,graph,visited,in,low,timer,AP);
            children++;
            low[v] = min (low[v],low[child]);
            
            if(low[child]>=in[v] && p!=-1){
                AP.insert(v);
            }

        }
    }

    if(p==-1 && children > 1 )
        AP.insert(v);
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
    set<int> AP;

    int timer = 0 ;

    // here we take 1 as vertex 
    for(int i=1 ;i<=n;i++){
        if(!visited[i]){
            DFS(i,-1,graph,visited,in,low,timer,AP);
        }
    }

    // Articulatin point print 
    cout<<"Articulation Point : ";
    for(auto &x:AP) 
        cout<<x<<" ";

    return 0;
}