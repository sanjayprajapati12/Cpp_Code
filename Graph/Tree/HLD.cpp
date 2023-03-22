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

const int size = 1e5+6;
const int lg = 20;

struct hld {
  vector<int> edges[size];
  int bigchild[size];
  int sz[size];
  int depth[size];
  int chain[size];
  int label[size], label_time;
  int par[size];
 
  int up[size][lg];
 
  int seg_tree[4 * size];
  int seg_lazy[4 * size];
 
  int N;
 
  /* ----------- segment tree ----------- */ 
 
  /* CHANGE THIS SECTION BY PROBLEM */
  inline int op(int a, int b) {
    return a ^ b;
  }
 
  inline int seg_lazy_apply(int lazy_val, int new_val) {
    return new_val;
  }
 
  inline int seg_lazy_func(int cur_val, int lazy_val, int l, int r) {
    return lazy_val;
  }
 
  const int seg_sentinel = 0;
  const int seg_lazy_sentinel = -1;
  const int seg_init_val = 0;
  /* END SECTION */
 
  int query(int l, int r) {
    return query(0, 0, N - 1, l, r);
  }
 
  int query(int i, int tl, int tr, int ql, int qr) {
    seg_eval_lazy(i, tl, tr);
 
    if (ql <= tl && tr <= qr) return seg_tree[i];
    if (tl > tr || tr < ql || qr < tl) return seg_sentinel;
 
    int mid = (tl + tr) / 2;
    int a = query(2 * i + 1, tl, mid, ql, qr);
    int b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return op(a, b);
  }
 
  void seg_update_header(int l, int r, int v) {
    seg_update_rec(0, 0, N - 1, l, r, v);
  }
 
  int seg_update_rec(int i, int tl, int tr, int ql, int qr, int v) {
    seg_eval_lazy(i, tl, tr);
 
	  if (tl > tr || tr < ql || qr < tl) return seg_tree[i];
    if (ql <= tl && tr <= qr) {
      seg_lazy[i] = seg_lazy_apply(seg_lazy[i], v);
      seg_eval_lazy(i, tl, tr);
      return seg_tree[i];
    }
    if (tl == tr) return seg_tree[i];
 
    int mid = (tl + tr) / 2;
    int a = seg_update_rec(2 * i + 1, tl, mid, ql, qr, v);
    int b = seg_update_rec(2 * i + 2, mid + 1, tr, ql, qr, v);
    return seg_tree[i] = op(a, b);
  }
 
  void seg_eval_lazy(int i, int l, int r) {
    if (seg_lazy[i] == seg_lazy_sentinel) return;
 
    seg_tree[i] = seg_lazy_func(seg_tree[i], seg_lazy[i], l, r);
 
    if (l != r) {
      seg_lazy[i * 2 + 1] = seg_lazy_apply(seg_lazy[i * 2 + 1], seg_lazy[i]);
      seg_lazy[i * 2 + 2] = seg_lazy_apply(seg_lazy[i * 2 + 2], seg_lazy[i]);
    }
 
    seg_lazy[i] = seg_lazy_sentinel;
  }
 
  /* ----------- init phase 1 ----------- */
  /* initialize segtree, clear edges, etc. */
 
  void init_arrays(int n) {
    // everything not initialized doesn't need to be
    N = n;
    for (int i = 0; i < N; i++) {
      edges[i].clear();
      chain[i] = i;
    }
 
    for (int i = 0; i < 4 * N; i++) {
      seg_tree[i] = seg_init_val;
      seg_lazy[i] = seg_lazy_sentinel;
    }
  }
 
  /* ----------- init phase 2 ----------- */
  /* put edges in */
 
  void add_edge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
 
  /* ----------- init phase 3 ----------- */
  /* build the lca and hld stuff */
 
  void init_tree(seg_t* arr, int root = 0) {
    // lca
    lca_dfs(root, -1);
 
    // size, compute biggest children
    dfs_size(root, -1, 0);
 
    // compute chains
    dfs_chains(root, -1);
 
    // label nodes
    label_time = 0;
    dfs_labels(arr, root, -1);
  }
 
  void lca_dfs(int v, int par) {
    up[v][0] = par;
 
    for (int i = 1; i < lg; i++) {
      if (up[v][i - 1] == -1) up[v][i] = -1;
      else up[v][i] = up[up[v][i - 1]][i - 1];
    }
 
    for (int x: edges[v]) {
      if (x != par) {
        lca_dfs(x, v);
      }
    }
  }
 
  void dfs_size(int v, int p, int d) {
    sz[v] = 1;
    depth[v] = d;
    par[v] = p;
    int bigc = -1, bigv = -1;
 
    for (int child: edges[v]) {
      if (child != p) {
        dfs_size(child, v, d + 1);
        sz[v] += sz[child];
        if (sz[child] > bigv) {
          bigc = child;
          bigv = sz[child];
        }
      }
    }
 
    bigchild[v] = bigc;
  }
 
  void dfs_chains(int v, int p) {
    if (bigchild[v] != -1) {
      chain[bigchild[v]] = chain[v];
    }
 
    for (int x: edges[v]) {
      if (x != p) {
        dfs_chains(x, v);
      }
    }
  }
 
  void dfs_labels(seg_t* arr, int v, int p) {
    label[v] = label_time++;
    seg_update_header(label[v], label[v], arr[v]);
 
    if (bigchild[v] != -1) {
      dfs_labels(arr, bigchild[v], v);
    }
 
    for (int x: edges[v]) {
      if (x != p && x != bigchild[v]) {
        dfs_labels(arr, x, v);
      }
    }
  }
 
  /* ----------- init phase 4 ----------- */
  /* usage */
 
  int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    int v = get_kth_ancestor(a, d);
    if (v == b) {
      return v;
    } else {
      for (int i = lg - 1; i >= 0; i--) {
        if (up[v][i] != up[b][i]) {
          v = up[v][i];
          b = up[b][i];
        }
      }
      return up[b][0];
    }
  }
 
  int get_kth_ancestor(int v, int k) {
    for (int i = lg - 1; i >= 0; i--) {
	    if (v == -1) return v;
      if ((1 << i) <= k) {
        v = up[v][i];
        k -= (1 << i);
      }
    }
    return v;
  }
 
  /* excludes p */
  int query_chain(int v, int p) {
    int val = seg_sentinel;
    while (depth[p] < depth[v]) {
      int top = chain[v];
      if (depth[top] <= depth[p]) {
        int diff = depth[v] - depth[p];
        top = get_kth_ancestor(v, diff - 1);
      }
      val = op(val, query(label[top], label[v]));
      v = par[top];
    }
    return val;
  }
 
  int query(int u, int v) {
    int lc = lca(u, v);
    int val = op(query_chain(u, lc), query_chain(v, lc));
    return op(val, query(label[lc], label[lc]));
  }
 
  /* excludes p */
  void update_chain(int v, int p, int val) {
    while (depth[p] < depth[v]) {
      int top = chain[v];
      if (depth[top] <= depth[p]) {
        int diff = depth[v] - depth[p];
        top = get_kth_ancestor(v, diff - 1);
      }
      seg_update_header(label[top], label[v], val);
      v = par[top];
    }
  }
 
  void update(int u, int v, int val) {
    int lc = lca(u, v);
    update_chain(u, lc, val); 
    update_chain(v, lc, val);
    seg_update_header(label[lc], label[lc], val);
  }
};


int32_t main(){

    int n,m;

    return 0;
}