#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
// given q query .q<=1e5
//  in each query you are given v.
// print subtree sum of v and number of even numbers in subtree v

int sub_sum[N];

void DFS(int v,int parent){
    sub_sum[v] = v;
    for(int child : graph[v]){
        if(child == parent)continue;
        DFS(child,v);
        sub_sum[v] += sub_sum[child];
    }
}

void reset(int n){
    for(int i=0 ;i<=n ;i++){
        sub_sum[i]=0;
    }
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
    reset(n);
    DFS(1,0);

    // for(int i=1 ; i<=n ;i++){
    //     cout<<i<<" "<<sub_sum[i]<<endl;
    // }
    
    int q;cin>>q;
    while(q--){
        int v;cin>>v;
        cout<<sub_sum[v]<<endl;
    }

    return 0;
}