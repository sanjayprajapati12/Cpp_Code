#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define INF 1e12

int32_t main(){

    int e,f;
    cin>>e>>f;

    // bottom-up DP
    vector<vector<int>> dp(e+1,vector<int> (f+1));

    for(int i=1 ; i<=e ; i++){
        for(int j=0 ; j<=f ; j++){
            if(i==1){
                dp[i][j]=j;
            }
            else if(j==1 || j==0){
                dp[i][j]=j;
            }
            else{
                int ans = INT_MAX;
                for(int mj = j-1 ,pj=0 ; mj >=0 ; mj --, pj++){
                    int v1 = dp[i][mj];  // egg survives
                    int v2 = dp[i-1][pj]; // egg breaks 
                    int v=max(v1,v2);
                    ans = min(ans,v);
                }
                dp[i][j] = ans + 1 ;
            }
        }
    }

    cout<<dp[e][f]<<endl;
    return 0;
}