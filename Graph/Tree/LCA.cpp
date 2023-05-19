#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>//
//#include<ext/pb_ds/tree_policy.hpp>//
using namespace std;
//using namespace __gnu_pbds;//

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif


#define int long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define rfo(i,n,x) for(int i=n; i>=x;i--) 
#define kill(x) cout<<x<<endl;continue;
#define OUTPUT(x) cout << (x ? "YES" : "NO")<<endl;
#define Output(x) cout << (x ? "Yes" : "No")<<endl;
#define output(x) cout << (x ? "yes" : "no")<<endl;
#define minv(v)    *min_element(v.begin(), v.end())
#define maxv(v)    *max_element(v.begin(), v.end())
#define sumv(v)    accumulate(v.begin(), v.end(), 0LL)
#define print(v)   for(auto k : v) cout<<k<<" "
#define all(v)   v.begin(),v.end()
#define rall(v)   v.rbegin(),v.rend()
#define p1(x)      cout<<x<<endl
#define p2(x,y)    cout<<x<<" "<<y<<endl
#define p3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<endl
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define vvi vector<vector<int>>
#define mod 1000000007
#define FILL(x,v) memset(x, v, sizeof(x))
#define PI 3.14159265358979323846
#define INF LLONG_MAX  //9.223372e+18
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;// 

struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
        size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}


int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}

struct LCA{
    const int LOG = 21;
    int n;
    vector<int> depth;
    vector<vector<int> > graph;
    vector<vector<int> > up;

    LCA(int sz) {
        n = sz;
        depth = vector<int>(n);
        graph = vector<vector<int> >(n, vector<int>());
        up = vector<vector<int> >(n, vector<int>(LOG, -1));
    }

    void edge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    void attach(int node_to_attach, int node_to_attach_to) {
        int a = node_to_attach, b = node_to_attach_to;
        edge(a, b);

        up[a][0] = b;

        for (int i = 1; i < LOG; i++) {
            if (up[a][i - 1] == -1) up[a][i] = -1;
            else up[a][i] = up[up[a][i - 1]][i - 1];
        }

        depth[a] = depth[b] + 1;
    }

    void init_up(int v = 0) {
        depth[v] = 0;
        dfs(v, -1);
    }

    void dfs(int v, int par) {
        up[v][0] = par;

        for (int i = 1; i < LOG; i++) {
            if (up[v][i - 1] == -1) up[v][i] = -1;
            else up[v][i] = up[up[v][i - 1]][i - 1];
        }

        for (int x : graph[v]) {
            if (x != par) {
                depth[x] = depth[v] + 1;
                dfs(x, v);
            }
        }
    }

    int get_kth(int v, int k) {
        for (int i = LOG - 1; i >= 0; i--) {
            if (v == -1) return v;
            if ((1 << i) <= k) {
                v = up[v][i];
                k -= (1 << i);
            }
        }
        return v;
    }

    int get_lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int k = depth[a] - depth[b];
        int v = get_kth(a, k);
        if (v == b) {
            return v;
        } else {
            for (int i = LOG - 1; i >= 0; i--) {
                if (up[v][i] != up[b][i]) {
                    v = up[v][i];
                    b = up[b][i];
                }
            }
            return up[b][0];
        }
    }

    int get_dist(int a, int b) {
        if(a==b)return 0LL;
        int v = get_lca(a, b);
        return (depth[a] + depth[b] - 2 * depth[v]);
    }
};

int32_t main(){
    fastio
    //cout<<setprecision(6)<<fixed<<ans<<endl;//
    //freopen( "input.txt" , "r" , stdin );//
    //freopen( "output.txt" , "w" , stdout );//
    
    // jaldi_karenge_jaldbaazi_nahi
    int t=1;
    // cin>>t;
    while(t--){
        int n;cin>>n;
        int m = n-1;
        LCA l(n);
        while(m--){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            l.edge(u,v);
        }
        l.init_up();
        
    }
    return 0;
}