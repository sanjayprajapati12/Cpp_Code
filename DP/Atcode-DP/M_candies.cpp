#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007

int32_t main(){

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a)cin>>x;

    vector<vector<int>> dp(n+1,vector<int>(k+1,0));

    for(int i=0 ; i<=a[0] ; i++){
        dp[0][i] = 1;
    }

    for(int i = 1 ; i<n;i++){
        auto pre = dp[i-1];
        for(int j=1 ; j<pre.size() ; j++){
            pre[j] += pre[j-1];
            if(pre[j]>=mod)pre[j]-=mod;
        }
        for(int j=0 ;j<=k;j++){
            int l = max(0ll,j-a[i]);
            dp[i][j] = pre[j];
            if(dp[i][j]>=mod)dp[i][j]-=mod;
            if(l>0){
                dp[i][j] = (dp[i][j]-pre[l-1]+mod)%mod;
            }

        }
    }
    
    cout<<dp[n-1][k]<<endl;
    return 0;
}