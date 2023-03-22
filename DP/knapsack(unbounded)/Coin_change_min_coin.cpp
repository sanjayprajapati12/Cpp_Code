#include<bits/stdc++.h>
using namespace std;
// unbounded knapsack

#define int long long int

int32_t main(){

    int n;
    cin>>n;
    int coin[n];
    // 1-indexed array 
    for(int i=1;i<=n;i++) cin>>coin[i];
    int sum;
    cin>>sum;

    vector<vector<int>> dp(n+1,vector<int>(sum+1,INT_MAX-1 ));
    for(int i=0 ; i<=n ; i++){
        dp[i][0]=0;
    }
      
    for(int i=1 ;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i]<=j)  
                dp[i][j] = min(dp[i - 1][j] , 1 + dp[i][j - coin[i]] );
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout<<dp[n][sum];
    return 0;
}