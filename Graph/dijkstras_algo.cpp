//  for both DG and UDG 
//  when we find our target's shortest distance then we break the loop
//  O(n+mlogm)

#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void addEdge(int a,int b,int w,vector<pair<int,int>> graph[]){
        graph[a].pb({b,w});
        // graph[b].pb({a,w});
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
    
    vector<int> d(n+1,INT_MAX);
    vector<int> p(n+1,-1);
    vector<bool> visited(n+1,0);
    // 1 as source
    d[1]=0;

    // we store {-d,a} in priority_queue
    priority_queue<pair<int, int>> pq;
    pq.push({0,1});
    while (!pq.empty()){
        int v = pq.top().second; 
        pq.pop();

        if (visited[v]) continue;
        visited[v] = true;

        for(auto u : graph[v]){
            int b = u.first;
            int w = u.second;
            if( d[v] + w < d[b] ){
                d[b] = d[v]+w;
                pq.push({-d[b],b});
                p[b] = v;
            }
        }
    }

    // print distance 
    for(int i=1 ; i<=n;i++){
        cout<<i<<" "<<d[i]<<endl;
    }
    
    // print shortest path
    // let say we want to find path from source->t [here source is 1]

    // stack<int> path;
    // int t;
    // cout<<"Please enter node which path you want : ";
    // cin>>t;
    // int s=1; // source
    // for (int v = t; v != s; v = p[v])
    //     path.push(v);
    // path.push(s);

    // while(!path.empty()){
    //     cout<<path.top()<<" ";
    //     path.pop();
    // }

    return 0;
}