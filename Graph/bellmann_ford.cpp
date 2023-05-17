// for undirected as well as directed
// shortest path
// find negative cycle 
//  Time [(node-1)*edges]

#include<bits/stdc++.h>
using namespace std;

// It should be noted that toSWhen running the Bellman-Ford algorithm with the point as the source point, if there is no negative cycle result, it can only be explained fromSStarting from a point cannot reach a negative cycle, but it cannot explain that there is no negative cycle on the graph.
// Therefore, if it is necessary to determine whether there is a negative cycle on the entire graph, the most rigorous approach is to establish a super source point, connect an edge with a weight of 0 to each node on the graph, and then execute the Bellman-Ford algorithm starting from the super source point .

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

    int source = 1;
    vector<int> d(n+1,INT_MAX);
    d[source]=0;
    bool x;
    for(int i=1 ; i<=n ; i++){
        x = true;
        for(auto it:graph){
            if(d[it.a]==INT_MAX){
                continue;
            }
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