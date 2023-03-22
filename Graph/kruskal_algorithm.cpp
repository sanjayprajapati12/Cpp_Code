// For minimum spanning tree(MST)
//  Time [(edges)*log(edges)]

#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
const int N = 1e5 + 5;
int p[N],size[N];

void make(int n){
    for(int i=1 ; i<=n ; i++){
        p[i]=i;
        size[i]=1;
    }
}

int findPar(int child){
    if(child != p[child]){
        p[child] = findPar(p[child]);
    }
    return p[child];
}

void unite(int a, int b){
    a = findPar(a);
    b = findPar(b);
    if (size[a] < size[b]) swap(a,b);
    size[a] += size[b];
    p[b] = a;
}

int32_t main(){
    
    // n--> nodes , m-->edges
    int n,m;
    cin>>n>>m;
    vector<pair< int, pair<int,int> > > edges;

    make(n);

    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        edges.pb({w,{a,b}});
    }

    sort(edges.begin(),edges.end());

    int cost = 0;
    vector<pair<int,int>> mst;
    
    for(auto it:edges){
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(findPar(u)!=findPar(v)){
            cost+=w;
            mst.pb({u,v});
            unite(u,v);
        }
    }

    cout<<cost<<endl;
    // printing mst
    for(auto it : mst ) cout<<it.first<<" - "<<it.second<<endl;

    return 0;
}