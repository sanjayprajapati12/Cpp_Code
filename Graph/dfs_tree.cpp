#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 10e5

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
    vector<pair<int,int>> bridge;
    // dp[x] -> back-edges passes over x and its parent
    vector<int> dp(n+1,0),lvl(n+1,-1);
    function<void(int,int)> dfs = [&](int p,int v){
        dp[v] = 0 ;
        // cout<<v<<endl;
        for(auto &child:graph[v]){
            if(lvl[child]==-1){
                lvl[child] = lvl[v] + 1;
                dfs(v,child);
                dp[v] += dp[child] ;
            }
            else if(lvl[child]<lvl[v]){
                dp[v]++ ;
            }
            else if(lvl[child]>lvl[v]){
                dp[v]--;
            }
        }
        dp[v]--;
        // cout<<"node "<<v<<" "<<dp[v]<<" "<<lvl[v]<<endl;
        if(lvl[v]>1 && dp[v]==0){
            bridge.push_back({v,p});
        }
    };

     
    lvl[1] = 1;
    dfs(-1,1);
    
    // for(int i=1 ; i<=n ;i++){
    //     cout<<"i -> "<<i<<" "<<dp[i]<<" "<<lvl[i]<<endl;
    // }

    cout<<"Bridge :"<<endl;
    for(auto &x:bridge){
        cout<<x.first<<" "<<x.second<<endl;
    }

    return 0;
}

// 7 8
// 1 2
// 2 3
// 1 3
// 3 6
// 3 5
// 2 4
// 4 5
// 5 7