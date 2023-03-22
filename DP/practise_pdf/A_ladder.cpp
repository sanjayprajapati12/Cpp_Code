
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define for(i,x,n) for(int i=x; i<=n;i++) 
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
    int n;
    cin>>n;
    int a[n+1];
    for(i,1,n) cin>>a[i];

    vector<int> dp(n+1,0);
    dp[1] = a[1];
    dp[2] = max(dp[1]+a[2],a[2]);
    for(i,3,n){
        dp[i] = a[i] + max(dp[i-1] , dp[i-2]) ;
    }
    cout<<dp[n];
    return 0;
}