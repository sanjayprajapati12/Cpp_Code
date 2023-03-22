//  for minimum spanning tree (MST)
// undirected graph

#include<bits/stdc++.h>
using namespace std;

#define pb push_back 

void addEdge(int a,int b,int w,vector<pair<int,int>> graph[]){
        graph[a].pb({b,w});
        graph[b].pb({a,w});
}

int32_t main(){
    
    // n--> nodes , m-->edges
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph[n+1];

    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        addEdge(a,b,w,graph);
    }

    vector<int> key(n+1,INT_MAX);
    vector<int> p(n+1,-1);
    vector<bool> mst(n+1,0);

    // 1 as source
    key[1]=0;

    // min heap
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;

    // we store {key[v],v}
    pq.push({0,1});

    for(int i=1 ; i<=n ; i++){
        int v = pq.top().second;
        pq.pop();
        if(mst[v])continue;
        mst[v]=true;
        
        for(auto it:graph[v]){
            int u = it.first;
            int weight = it.second; 
            if(mst[u]==false && weight<key[u]){
                key[u]=weight;
                pq.push({key[u],u});
                p[u]=v;
            }
        }
    }
    
    // print mst
    for(int i=2 ;i<=n;i++){
        cout<<p[i]<<" "<<i<<"\n";
    }

    
    return 0;
}