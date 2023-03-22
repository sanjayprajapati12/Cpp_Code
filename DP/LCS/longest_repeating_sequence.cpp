#include<bits/stdc++.h>
using namespace std;

#define int long long int

int recurance(string s1,string s2,int n,int m){
    if(n==0 || m==0) return 0;
    else{
        if(s1[n-1]==s2[m-1]){
            return (1 + recurance(s1,s2,n-1,m-1));
        }
        else{
            return max(recurance(s1,s2,n,m-1), recurance(s1,s2,n-1,m));
        }
    }
}


int32_t main(){

    string s1;
    cin>>s1;
    int n = s1.size();
    // cout<<recurance(s1,s2,n,m);


    // bottom-up DP
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = 1 ; i<=n;i++){
        for(int j=1 ;j<=n;j++){
            if(s1[i-1]==s1[j-1]  &&  i!=j ){
                dp[i][j]= dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][n]<<endl;
    
    return 0;
}