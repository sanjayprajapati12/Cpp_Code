#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){

    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();


    // bottom-up DP with space--> O(N*M)
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

    // Printing lcs 
    int ans = dp[n][m];
    char lcs[ans+1];
    lcs[ans]='\0';

    int i=n,j=m;
    while(i>0 || j>0){
        if(i && j && s1[i-1]==s2[j-1]){
            ans--;
            lcs[ans]=s1[i-1];
            i--;
            j--;
            continue;
        }
        if(i==0){
            j--;
            continue;
        }
        if(j==0){
            i--;
            continue;
        }
        if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }

    cout<<lcs<<endl;
    
    return 0;
}