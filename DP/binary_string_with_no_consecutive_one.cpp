#include<bits/stdc++.h>
#define ll long long
using namespace std;

// given n(length of binary string). 
// return no. of binary string with no consecutive one's 
// of length n

int main(){
    
    int n;cin>>n;
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    // dp[i][0] - string end with 0 having i length
    // dp[i][1] - string end with 1 having i length
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2 ; i<=n ; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0] ; 
    }
    int ans = dp[n][0] + dp[n][1];
    cout<<ans<<endl;

    return 0;
}