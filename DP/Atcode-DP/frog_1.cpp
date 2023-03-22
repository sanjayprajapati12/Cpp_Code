
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
    vector<int> dp(n+1,INT_MAX);
    dp[1] = 0;
    dp[2] = abs(a[2]- a[1]);
    dp[3] = min( abs(a[3]-a[1] ) ,abs(a[3] - a[2]) + dp[2]);
    for(i,4,n){
        dp[i] = min(dp[i-1] + abs(a[i]-a[i-1]) , dp[i-2] + abs(a[i]-a[i-2])) ;
    }
    cout<<dp[n];
    return 0;
}