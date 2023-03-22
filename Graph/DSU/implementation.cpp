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
        if(node != p[node]){
            p[node] = findPar(p[node]);
        }
        return p[node];
    }
    
    void unite(int a, int b){
        a = findPar(a);
        b = findPar(b);
        if(a==b) return;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        parent[b] = a;
    }
};

// connected components
void cc(int n,DSU &dsu)
{
    set<int> s;
    for (int i = 1; i <=n; i++) {
        s.insert(dsu.findPar(i));
    }
    cout << s.size() << '\n';
}

int32_t main(){

    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    while(m--){
        int u,v;
        cin>>u>>v;
        dsu.unite(u,v);
    }

    cc(n,dsu);
    // for(int i = 0 ; i<=n;i++){
    //     cout<<"i "<<dsu.parent[i]<<endl;
    // }
    return 0;
}