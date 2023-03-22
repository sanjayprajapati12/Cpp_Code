#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];

// depth means distance from root node to current node
vector<int> d(N);

// height means  max distance from leaf node to current node
vector<int> h(N);

void DFS(int v,int parent){
    // Take action on vertex after entering the vertex
    for(int child : graph[v]){
        // take action on child before entering the child node 

        if(child == parent)continue;
        d[child] = d[v] + 1;
        DFS(child,v);
        // take action on child after exiting child node
        h[v] = max(h[v] , h[child] + 1);
    }
    // take action on vertex before exiting the vertex
}

int32_t main(){
    int n;cin>>n;
    int m = n-1; // edges
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    DFS(1,0);
    int mx_depth = -1;
    int mx_depth_node ;
    for(int i=1 ;i<=n ;i++){
        if(mx_depth<d[i]){
            mx_depth = d[i];
            mx_depth_node = i;
        }
        // reset 
        d[i]=0;
    }
    mx_depth = -1;
    DFS(mx_depth_node,0);
    for(int i=1 ; i<=n ;i++){
        mx_depth = max(mx_depth,d[i]);
    }
    cout<<mx_depth<<endl;

    return 0;
}