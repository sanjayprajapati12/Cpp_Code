#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 10e5

vector<int> d(N+1,0);  // store distance
vector<int> p(N+1);  // store parent
bool bipartiteDFS(int v,vector<int> graph[],vector<int> color){
    if(color[v] == (-1)) color[v]=1;
    for(auto child : graph[v]){
        if(color[child]==(-1)){
            color[child] = 1 - color[v];
            if(!bipartiteDFS(child,graph,color))
                return false;
        }
        else if(color[child]==color[v] && color[child]!=(-1))
            return false;
    }
    return true;
}

// for multipale component 
bool checkBipartite(vector<int> graph[] , int n){
    vector<int> color(n+1,-1);   //like visited 
    for(int i=1 ;i<=n;i++){
        if(color[i]==-1){
            if(!bipartiteDFS(i,graph,color))
                return false;
        }
    }
    return true;
}

void addEdge(int a,int b,vector<int> graph[]){
        graph[a].pb(b);
        graph[b].pb(a);
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
   
    if(checkBipartite(graph,n)) cout<<"YES : we can color"<<endl;
    else cout<<"NO : we can't color "<<endl;

    return 0;
}