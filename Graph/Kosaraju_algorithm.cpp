// find strongly connected component
// 2 dfs
// strongly connented = conected component in directed graph
// O(n+m)

#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
struct SCC{
	int n;
	vector<vector<int>> graph, tr_graph,con_graph;
	vector<int> topo, scc_node, root;
	vector<bool> vis;

	void init(int _N) {
		n = _N;
		graph.resize(n),
		con_graph.resize(n),
        tr_graph.resize(n),
        root = vi(n, -1),
        vis.resize(n);
	}

	void add_edge(int x, int y) { 
        graph[x].pb(y), 
        tr_graph[y].pb(x); 
    }

	void dfs(int v) {
		vis[v] = true;
        for(auto &child:graph[v]){
            if(vis[child])continue;
            dfs(child);
        }
        topo.push_back(v);
	}
    
	void dfs2(int v, int r) {
		root[v] = r;
        for(auto &child:tr_graph[v]){
            if(root[child]!=-1)continue;
            dfs2(child,r);
        }
	}

	void gen(){ 
        for(int i=0 ; i<n ; i++){
            if(vis[i])continue;
            dfs(i);
        }		
		reverse(all(topo));

        for(int i=0 ; i<n ; i++){
            if(root[topo[i]]!=-1)continue;
            dfs2(topo[i],topo[i]);
            scc_node.push_back(topo[i]);
        }
	}

    void make_condese(){
        for(int i=0 ; i<n ; i++){
            for(auto &child:graph[i]){
                if(root[child]==root[i])continue;
                con_graph[root[i]].push_back(root[child]);
            }
        }
    }
};

int32_t main(){
    
    int n,m;
    cin>>n>>m;
    SCC sc;
    sc.init(n);

    while(m--){
        int a,b;
        cin>>a>>b;
        sc.add_edge(a,b);
    }
    sc.gen();
    sc.make_condese();


    return 0;
}