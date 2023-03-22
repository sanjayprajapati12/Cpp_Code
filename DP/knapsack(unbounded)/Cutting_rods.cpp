#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){

    int n;
    cin>>n;
    int price[n];
    // 1-indexed array 
    for(int i=1;i<=n;i++) cin>>price[i];

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int i=1 ; i<n+1;i++){
        for(int j=1 ;j<n+1;j++){
            if(i<=j)
                dp[i][j] = max(dp[i - 1][j] , price[i] + dp[i][j-i] );
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout<<dp[n][n];
    return 0;
}