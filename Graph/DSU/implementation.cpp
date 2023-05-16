#include<bits/stdc++.h>
using namespace std;


struct DSU{
    vector<int> sz;
    vector<int> parent;

    void make_set(int n){
        for(int i=0 ; i<=n;i++){
            parent[i]=i;
            sz[i]=1;
        }
    }

    DSU(int n){
        parent.resize(n+1);
        sz.resize(n+1);
        make_set(n);
    }

    int findPar(int node){
        if(node != parent[node]){
            parent[node] = findPar(parent[node]);
        }
        return parent[node];
    }
    
    void unite(int a, int b){
        a = findPar(a);
        b = findPar(b);
        if(a==b) return;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        parent[b] = a;
    }

    int connected_component(int n){
        set<int> s;
        for(int i=1 ; i<=n ; i++){
            s.insert(findPar(i));
        }
        return s.size();
    }
};

int32_t main(){

    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    while(m--){
        int u,v;
        cin>>u>>v;
        dsu.unite(u,v);
    }

    cout<<dsu.connected_component(n)<<endl;
    return 0;
}