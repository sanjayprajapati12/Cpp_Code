#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>//
//#include<ext/pb_ds/tree_policy.hpp>//
using namespace std;
//using namespace __gnu_pbds;//


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

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif


void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}


int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}

struct centroid {
  vector<vector<int>> graph;
  vector<vector<int>> cen_graph;
  vector<bool> vis;
  vector<int> par;
  vector<int> sz;
  int root;
  int n;
 
  centroid(int s) {
    n = s;
    graph = vector<vector<int> >(n, vector<int>());
    cen_graph = vector<vector<int> >(n, vector<int>());
    vis = vector<bool>(n, 0);
    par = vector<int>(n);
    sz = vector<int>(n);
  }
 
  void edge(int a, int b) {
    graph[a].pb(b);
    graph[b].pb(a);
  }
  
  int find_size(int v, int p = -1) {
    if (vis[v]) return 0;
    sz[v] = 1;
 
    for (auto &child: graph[v]) {
      if (child != p) {
        sz[v] += find_size(child, v);
      }
    }

    return sz[v];
  }
 
  int find_centroid(int v, int p, int n) {
    for (auto &child: graph[v]) {
      if (child != p) {
        if (!vis[child] && sz[child] > n / 2) {
          return find_centroid(child, v, n);
        }
      }
    }
    return v;
  }
 
  void init_centroid(int v = 0, int p = -1) {
    find_size(v);
 
    int c = find_centroid(v, -1, sz[v]);
    vis[c] = true;
    par[c] = p;

    for (int x: graph[c]) {
      if (!vis[x]) {
        init_centroid(x, c);
      }
    }
  }

  void make_centroid_graph(){
    fo(i,0,n-1){
        if(par[i]!=-1){
            cen_graph[i].push_back(par[i]);
            cen_graph[par[i]].push_back(i);
        }
        else{
            root = i;
        }
    }
  }
  
};


int32_t main(){
    int n ;cin>>n;
    centroid cen(n);
    int m = n-1;
    while(m--){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        cen.edge(a,b);
    }
    cen.init_centroid();
    cen.make_centroid_graph();
    return 0;
}