#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
void toposortDFS(int v,vector<pair<int,int>> graph[],bool visited[],stack<int> &st){
    visited[v] = true ;
    for(auto child : graph[v]){
        if(!visited[child.first]){
            toposortDFS(child.first,graph,visited,st);
        }
    }
    st.push(v);
}

void shortestPath(int v,int n,vector<pair<int,int>> graph[]){
    bool visited[n+1] ={false};
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!visited[i])
            toposortDFS(i,graph,visited,st);
    }

    vector<int> d(n+1,INT_MAX);
    d[v]=0;
    
    while (!st.empty()){
        int v = st.top();
        st.pop();
        if(d[v]!=INT_MAX){
            for(auto u:graph[v]){
                d[u.first] = min(d[u.first] , d[v] + u.second);
            }
        }
    }

    for(int i=1 ;i<=n;i++){
        (d[i]==INT_MAX) ? cout<<"INF " : cout<<d[i]<<" ";
    } 
    cout<<endl;
    
}

void addEdge(int a,int b,int w,vector<pair<int,int>> graph[]){
        graph[a].pb({b,w});
}
 
int32_t main(){
    
    // n--> nodes , m-->edges
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph[n+1];
    
    bool visited[n+1] = {};
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        addEdge(a,b,w,graph);
    }

    shortestPath(1,n,graph);
    
    return 0;
}