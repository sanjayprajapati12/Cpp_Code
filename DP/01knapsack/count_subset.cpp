#include<bits/stdc++.h>
using namespace std;


#define int long long int

int32_t main(){

    int n;
    cin>>n;
    int a[n];
    // 1-indexed array 
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum;
    cin>>sum;

    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i=0 ; i<=n ; i++){
        dp[i][0]=1;
    }

    for(int i=1 ;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i]<=j)  
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout<<dp[n][sum];
    return 0;
}