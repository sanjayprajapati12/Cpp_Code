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

    cout<<"Depth"<<endl;
    for(int i=1 ;i<=n ;i++){
        cout<<i<<" "<<d[i]<<endl;
    }
    cout<<endl;
    
    cout<<"Height"<<endl;
    for(int i=1 ;i<=n ;i++){
        cout<<i<<" "<<h[i]<<endl;
    }
    return 0;
}