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

    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    // cout<<recurance(s1,s2,n,m);

    // bottom-up DP
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    int ans=0,ie;
    
    for(int i = 1 ; i<=n;i++){
        for(int j=1 ;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]= 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
                if(ans==dp[i][j]) ie=i-1; // for printing purpose
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    cout<<ans<<endl;

    // printing the substring
    char substring[ans+1];
    substring[ans]='\0';
    while(ans--){
        substring[ans]=s1[ie];
        ie--;
    }
    cout<<substring<<endl;
    return 0;
}