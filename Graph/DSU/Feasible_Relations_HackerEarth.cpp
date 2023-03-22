#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
int p[N]={0};
int si[N]={0};

void makeSet(int n){
    for(int i=1 ; i<=n;i++){
        p[i]=i;
        si[i]=1;
    }
}

int findPar(int node){
    while (node != p[node]) node = p[node];
    return node;
}

void unite(int a, int b) {
    a = findPar(a);
    b = findPar(b);
    if (si[a] < si[b]) swap(a,b);
    si[a] += si[b];
    p[b] = a;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        makeSet(n);
        vector<pair<int,int>> vp;
        while(m--){
            int u,v;
            string s;
            cin>>u;
            cin>>s;
            cin>>v;
            if(s.length()==1)
                unite(u,v);
            else vp.push_back({u,v});
        }

        bool flag=true;
        for(auto &x:vp){
            if(findPar(x.first)==findPar(x.second)) {
                cout<<"NO"<<endl;
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
    }


    return 0;
}