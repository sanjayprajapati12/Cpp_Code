#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define rfo(i,n,x) for(int i=n; i>=x;i--)
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define mod 1000000007
    
int32_t main(){
    int a[9][9];
    fo(i,1,8){
        fo(j,1,8) cin>>a[i][j];
    }

    vector<vector<int>> dp(9,vector<int> (9,0));
    dp[8][1] = a[8][1];
    rfo(i,8,1){
        fo(j,1,8){
            if(j>1 && (i)<8) dp[i][j] = a[i][j] + min(dp[i+1][j-1],min(dp[i+1][j],dp[i][j-1]));
            if(j==1 && (i)<8) dp[i][j] = a[i][j] + dp[i+1][j];
            if(j>1 && (i)==8) dp[i][j] = a[i][j] + dp[i][j-1];
        }
    }

    // print all the cases 
    
    // fo(i,1,8){
    //     fo(j,1,8)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    cout<<dp[1][8]<<endl;
    return 0;
}