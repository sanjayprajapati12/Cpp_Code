#include<bits/stdc++.h>
using namespace std;


#define int long long int

int32_t main(){

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    
    int ans = INT_MIN ;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));

    // kadane's low
    for(int i=1 ; i<=n ; i++){
        dp[i][0]= max(a[i-1],a[i-1] + dp[i-1][0]);
        ans = max(ans,dp[i][0]);
    }

    for(int i=1 ;i<n+1;i++){
        for(int j=1;j<k+1;j++){
            dp[i][j] = max(max(a[i-1],a[i-1] + dp[i-1][j]) ,dp[i-1][j-1]);
            ans = max(ans,dp[i][j]); 
        }
    }

    cout<<ans<<endl;
    return 0;
}