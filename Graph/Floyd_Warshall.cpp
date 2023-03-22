//  for shortest path
// undirected graph
// O(n^3) - so this only use when graph is small
// handle negetive wight , but not negetive cycle

#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
#define INF 1e12


int32_t main(){
    
    // n--> nodes , m-->edges
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1,vector<int> (n+1,0));

    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a][b]=w;
        graph[b][a]=w;
    }

    vector<vector<int>> d(n+1,vector<int> (n+1,INF));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i==j) d[i][j]=0;
            else if(graph[i][j]) d[i][j]=graph[i][j];
        }
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(d[i][k]==INF || d[k][j]==INF)continue;
                d[i][j] = min(d[i][j] , d[i][k]+d[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(d[i][j]==INF)cout<<"I ";
            else cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}