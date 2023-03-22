#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define float long double
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast")
#ifndef ONLINE_JUDGE
#include "dbg.hpp"
#else
#define debug(...) 8
#endif
struct two_sat {
    int n;
    vector<vector<int>> g, gr; // gr is the reversed graph
    vector<int> comp, topological_order, answer; // comp[v]: ID of the SCC containing node v
    vector<bool> vis;

    two_sat() {}

    two_sat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        comp.resize(2 * n);
        vis.resize(2 * n);
        answer.resize(2 * n);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // For the following three functions
    // int x, bool val: if 'val' is true, we take the variable to be x. Otherwise we take it to be x's complement.

    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    // Only one of them is true
    void add_clause_xor(int i, bool f, int j, bool g) {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }

    // Both of them have the same value
    void add_clause_and(int i, bool f, int j, bool g) {
        add_clause_xor(i, !f, j, g);
    }

    // Topological sort
    void dfs(int u) {
        vis[u] = true;

        for (const auto &v : g[u])
            if (!vis[v]) dfs(v);

        topological_order.push_back(u);
    }

    // Extracting strongly connected components
    void scc(int u, int id) {
        vis[u] = true;
        comp[u] = id;

        for (const auto &v : gr[u])
            if (!vis[v]) scc(v, id);
    }

    // Returns true if the given proposition is satisfiable and constructs a valid assignment
    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) dfs(i);

        fill(vis.begin(), vis.end(), false);
        reverse(topological_order.begin(), topological_order.end());

        int id = 0;
        for (const auto &v : topological_order)
            if (!vis[v]) scc(v, id++);

        // Constructing the answer
        for (int i = 0; i < n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }

        return true;
    }
};

void solve(){
  int n,m;
  cin>>n>>m;
  two_sat st(n+1);
  for(int i=1;i<=m;i++){
    int a,b,c;
    string s;
    cin>>a>>b>>s>>c;
    if(s=="="){
      if(c==0){ //a=0,b=0
        st.add_clause_or(a,0,a,0);
        st.add_clause_or(b,0,b,0);
      }
      else if(c==1){ //a=0,1 b=0,1
        st.add_clause_or(a,0,b,0);
        st.add_clause_or(a,1,b,1);
      }
      else{ //a=1,b=1
        st.add_clause_or(a,1,a,1);
        st.add_clause_or(b,1,b,1);
      }
    }
    else if(s=="!="){
      if(c==0){ // a+b=1 or a+b=2
        st.add_clause_or(a,1,b,1);
      }
      else if(c==1){ //a+b=0 or a+b=2
        st.add_clause_or(a,0,b,1);
        st.add_clause_or(a,1,b,0);
      }
      else{ //a+b=0 or a+b=1
        st.add_clause_or(a,0,b,0);
      }
    }
    else if(s=="<"){
      if(c==0){ //FALSE NO
        st.add_clause_or(a,0,a,0);
        st.add_clause_or(a,1,a,1);
      }
      else if(c==1){ //a+b=0
        st.add_clause_or(a,0,a,0);
        st.add_clause_or(b,0,b,0);
      }
      else{ //a+b=0 or a+b=1
        st.add_clause_or(a,0,b,0);
      }
    }
    else if(s==">"){
      if(c==0){ //a+b=1 or a+b=2
        st.add_clause_or(a,1,b,1);
      }
      else if(c==1){ //a+b=2
        st.add_clause_or(a,1,a,1);
        st.add_clause_or(b,1,b,1);
      }
      else{ //False
        st.add_clause_or(a,0,a,0);
        st.add_clause_or(a,1,a,1);
      }
    }
    else if(s=="<="){
      if(c==0){ //a+b=0
        st.add_clause_or(a,0,a,0);
        st.add_clause_or(b,0,b,0);
      }
      else if(c==1){ //a+b < 2
        st.add_clause_or(a,0,b,0);
      }
    }
    else if(s==">="){
      if(c==1){ //a+b>0
        st.add_clause_or(a,1,b,1);
      }
      else if(c==2){ //a+b=2
        st.add_clause_or(a,1,a,1);
        st.add_clause_or(b,1,b,1);
      }
    }
  }
  if(st.satisfiable()){
    cout<<"Yes\n";
  }
  else{
    cout<<"No\n";
  }
}

int  main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
}