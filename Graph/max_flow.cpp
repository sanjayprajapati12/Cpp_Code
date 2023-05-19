#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>//
//#include<ext/pb_ds/tree_policy.hpp>//
using namespace std;
//using namespace __gnu_pbds;//
 
 
// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define debug(...)
// #endif
 
 
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
 
struct Flow {
    int n;

    struct Edge {
        int to, cap;
        Edge(int _to ,int _cap){
            to = _to ;
            cap = _cap ; 
        }
    };
 
    vector<Edge> e;
    vector<int> visited;
    int iteration = 0 ;
    vector<vector<int>> g;
    vector<int> cur, dist;
    Flow(int _n){
        n = _n ; 
        g.resize(n);
        visited.resize(n);
    }
 
    bool bfs(int source, int sink) {
        dist.assign(n, -1);
        queue<int> que;
        dist[source] = 0;
        que.push(source);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i : g[u]) {
                int to = e[i].to;
                int cap = e[i].cap;
                if (cap > 0 && dist[to] == -1) {
                    dist[to] = dist[u] + 1;
                    if (to == sink)
                        return true;
                    que.push(to);
                }
            }
        }
        return false;
    }
 
    int dfs(int u, int sink, int cur) {
        visited[u] = iteration;
        if (u == sink)
            return cur;
        int r = cur;
        for(auto &j : g[u]){
            int to = e[j].to;
            int cap = e[j].cap;
            if (visited[to]!=iteration && cap > 0 && dist[to] == dist[u] + 1) {
                int a = dfs(to, sink, min(r, cap));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                    return cur;
            }
        }
        return cur - r;
    }
 
    void addEdge(int u, int v, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
 
    int maxFlow(int source, int sink) {
        int ans = 0;
        while (bfs(source, sink)) {
            cur.assign(n, 0);
            iteration++;
            ans += dfs(source, sink, INF);
        }
        return ans;
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
        int n,m;
        cin>>n>>m;
        Flow g(n);
        while(m--){
            int u,v,c;
            cin>>u>>v>>c;
            u--;
            v--;
            g.addEdge(u,v,c);
        }
        cout<<g.maxFlow(0,n-1)<<endl;
    }
    return 0;
}