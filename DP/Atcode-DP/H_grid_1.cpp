#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define int long long int
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define mod 1000000007
#define INF 1e9 
    
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n+1,vector<char> (m+1,0));
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    for(int row = 1  ; row<=n ;row++){
        for(int col=1 ; col<=m ; col++){
            cin>>grid[row][col];
            if(grid[row][col]=='#'){
                dp[row][col] = -1;
            }
        }
    }
    dp[1][1] = 1;
    fo(i,1,n){
        fo(j,1,m){
            if(dp[i][j]==-1)continue;
            if(dp[i][j-1]!=-1) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            if(dp[i-1][j]!=-1) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
        }
    }

    cout<<dp[n][m]%mod<<endl;   

    return 0;
}