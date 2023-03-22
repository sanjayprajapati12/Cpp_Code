#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void addEdge(int a,int b,vector<int> graph[]){
        graph[a].pb(b);
        graph[b].pb(a);
}

int32_t main(){

    int n; // number of nodes
    int m; // no of edges
    cin>>n>>m;
    vector<int> graph[n+1];  

    // make graph
    while(m--){
        int a,b;
        cin>>a>>b;
        addEdge(a,b,graph);
    }

    queue<int> q;
    vector<int> color(n+1,-1);

    // BFS
     for(int i=1 ;i<=n ; i++){
        if(color[i]==-1){
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : graph[v]) {
                    if (color[u]==-1) {
                        color[u] = 1 - color[v];
                        q.push(u);
                    }
                    else if(color[v]==color[u]){
                        cout<<"No : we cann't color "<<endl;
                        return 0;
                    }
                }
            }
        }
    }

        // another implementation   
        bool is_bip = true;
        vector<bool> used(n, false);
        for (int j = 0; j < n; j++){
            if (!used[j]){
                queue<int> Q;
                used[j] = true;
                Q.push(j);
                int cv = 0, ce = 0;
                while (!Q.empty()){
                    int v = Q.front();
                    Q.pop();
                    cv++; // count of vertices
                    for (int child : graph[v]){
                        ce++;
                        if (!used[child]){
                            used[child] = true;
                            Q.push(child);
                        }
                    }
                }
                ce /= 2; //count of edges 
                if (ce == cv && cv % 2 == 1){
                    is_bip = false;
                    break;
                }
            }
        }
    
        cout<<"YES : we can color " <<endl;

 return 0;
}  