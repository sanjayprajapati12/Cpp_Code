#include<bits/stdc++.h>
using namespace std;
// Find count of numbers in range [1,n] such that sum of its digits is a prime number.

bool isPrime(int n){
    if(n==1) return false;
    if(n==2) return true;
    for (int i = 2; i <=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

int digit_dp(string ss) {
    int n = ss.size();
    // int dp[20][2][200];
    // memset(dp,0,sizeof dp);
    int dp[20][2][200];
    memset(dp,0,sizeof dp);
    // vector<vector<vector<int>>> d(z, vector<vector<int>>(y, vector<int> (x, value)));
    //empty suffixes having sum=0
    dp[n][0][0] = 1;
    dp[n][1][0] = 1;
 
    for(int i = n-1; i >=0 ; i--) {
        for(int tight = 0; tight < 2 ; tight++) {
            for(int sum = 0; sum < 200 ; sum++) {
                if(tight) {
                    for(int d = 0; d <= ss[i] - '0' ; d++) {
                        dp[i][1][sum] += (d == ss[i]-'0') ? dp[i+1][1][sum-d] : dp[i+1][0][sum-d];
                    }
                }
                else {
                    for(int d = 0; d < 10 ; d++) {
                        dp[i][0][sum] += dp[i+1][0][sum-d];
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 200; i++) {
        if(isPrime(i)) ans += dp[0][1][i];
    }
    return ans;
}

int32_t main(){

    string s;
    cin>>s;

    cout<<digit_dp(s)<<endl;
    return 0;
}