#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
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

    int n,p;
    cin>>n>>p;

    vector<vector<int>> dp(n+1,vector<int> (p+1,0));

    fo(i,1,p) dp[1][i]=1;

    fo(i,2,n){
        fo(j,1,p){
            int k=j%i;
            dp[i][j] = (dp[i-1][j] + k )  ;
            if(dp[i][j]>i) dp[i][j]%=i;
        }
    }

    cout<<dp[n][p]<<endl;
    return 0;
}