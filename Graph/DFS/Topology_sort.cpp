// DAG have it -> Directed Acyclic Graph
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
void toposortDFS(int v,vector<int> graph[],bool visited[],stack<int> &st){
    visited[v] = true ;
    for(auto child : graph[v]){
        if(!visited[child]){
            toposortDFS(child,graph,visited,st);
        }
    }
    st.push(v);
    // cout<<v<<" "; simple change in simple DFS
}

void addEdge(int a,int b,vector<int> graph[]){
        graph[a].pb(b);
}

int32_t main(){
    // n--> nodes , m-->edges
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];

    while(m--){
        int a,b;
        cin>>a>>b;
        addEdge(a,b,graph);
    }
    
    bool visited[n+1] = {false};
    stack<int> st; // for storing element 
    // here we take 1 as vertex 
    for(int i=1 ;i<=n;i++){
        if(!visited[i]){
            toposortDFS(i,graph,visited,st);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}