#include<bits/stdc++.h>
using namespace std;
//  cc should be 1 and cycle is not there ( means nodes==edges+1)
#define endl '\n'

void dfs(int v , vector<int> graph[] , bool visited[]){
    visited[v]=true;
    for(auto u:graph[v]){
        if(!visited[u])
            dfs(u,graph,visited);
    }
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    int l=m;
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool visited[n+1]= {false};

    int c=0;

    for(int i=1 ; i<n+1 ;i++){
        if(visited[i]==false){
            dfs(i,graph,visited);
            c++;
        }
    }

    if(c==1 && n==(l+1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}