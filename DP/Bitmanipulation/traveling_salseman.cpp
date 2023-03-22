#include<bits/stdc++.h>
using namespace std;

// not done yet
// https://www.hackerrank.com/contests/code-wars-4-0-csikjsce/challenges/delhi-tourism/problem 

const int INF = 1e5;

int32_t main(){

    int n;
    cin>>n;
    int distance[n][n];
    for(int i=0 ; i<n ;i++){
        for(int j=0 ;j<n ;j++){
            cin>>distance[i][j];
        }
    }
    double m,c;
    cin>>m>>c;

    
    // bottom-up approch
    vector<vector<int>> dp(n,vector<int> (1<<n,INF));
    // dp[i][S] - means what is the min distance to reach 1 after visiting all city's in S {subset}
    
    // base case
    // dp[i][0] - means reaching i without visiting any city
    int origin = 0; 
    dp[origin][1<<origin] = 0;
    for(int i=0 ; i<n ;i++){
        dp[i][1<<origin] = distance[i][0];
    }

    for(int mask=1 ; mask<(1<<n) ; mask++){
        for(int end = 0; end < n; end++){
            if((mask>>end)&1){
                for(int start = 0 ; start<n ; start++){
                    if(start==end)continue;
                    if((mask>>start)&1){
                        dp[end][mask] = min(dp[end][mask] , dp[start][mask^(1<<end)] + distance[start][end]);  
                    }
                }
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < (1<<n); j++)
    //     {
    //         cout<<dp[i][j]<<" ";

    //     }
    //     cout<<endl;
    // }
    
    double ans = (double)dp[1][(1<<n)-1];
    ans*=(c/m);
    cout<<setprecision(2)<<fixed<<ans<<endl;
    return 0;
}
