// for undirected as well as directed
// shortest path
// find negative cycle 
//  Time [(node-1)*edges]

#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
struct node{
    int a;
    int b;
    int w;
    node(int first , int second , int weight){
        a=first;
        b=second;
        w=weight;
    }
};

int32_t main(){
    
    // n--> nodes , m-->edges
    int n,m;
    cin>>n>>m;
    vector<node> graph;

    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        graph.pb((node(a,b,w)));
    }

    vector<int> d(n+1,INT_MAX);
    d[1]=0;
    bool x;
    for(int i=1 ; i<=n ; i++){
        x = true;
        for(auto it:graph){
            // if change doen't happen than u break 
            if(d[it.b] > d[it.a]+it.w){
                d[it.b] =  d[it.a] + it.w ;
                x=false;
            }
        }
        if(x) break;
    }

    // check negative length cycle 
    if(x){
        for(int i=1 ; i<=n;i++){
            cout<<i<<" "<<d[i]<<endl;
        }
    }
    else{
        cout<<"Negative Cycle"<<endl;
    }

    return 0;
}