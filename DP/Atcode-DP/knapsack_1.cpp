

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define for(i,x,n) for(int i=x; i<=n;i++) 
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
    
int32_t main(){
    int n,total_w;
    cin>>n>>total_w;
    int w[n+1];
    int price[n+1];
    for(i,1,n){
        cin>>w[i];
        cin>>price[i];
    }

    vector<vector<int>> dp(n+1,vector<int> (total_w+1,0));

    for(i,1,n){
        for(j,1,total_w){
            if(w[i]<=j)
                dp[i][j] = max (dp[i-1][j] , price[i] + dp[i-1][j-w[i]]) ;
            else  
                dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[n][total_w];   

    return 0;
}