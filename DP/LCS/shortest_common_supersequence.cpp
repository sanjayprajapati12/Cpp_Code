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
    for(int i = 1 ; i<=n;i++){
        for(int j=1 ;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]= dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans = n + m - dp[n][m];
    cout<<ans<<endl;
    
    // Printing
    string lcs = " ";

    int i=n,j=m;
    while(i>0 || j>0){
        if(s1[i-1]==s2[j-1]){
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]){

            lcs.push_back(s2[j-1]);
            j--;
        }
        else{

            lcs.push_back(s1[i-1]);
            i--;
        }
    }
    while(i>0){
        lcs.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        lcs.push_back(s2[j-1]);
        j--;
    }
    reverse(lcs.begin(),lcs.end());
    cout<<lcs<<endl;
    return 0;
}