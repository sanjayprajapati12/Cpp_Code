
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
    int n,k;
    cin>>n>>k;
    int a[n+1];
    fo(i,1,n) cin>>a[i];
    vector<int> dp(n+1,INT_MAX);
    dp[1] = 0 ;
    dp[2] = abs(a[2]- a[1]);
    fo(i,3,n){
        fo(j,1,k){
            if((i-j)>0)
                dp[i] = min ( dp[i] , dp[i-j] + abs(a[i] - a[i-j])) ;
        }
    }
    cout<<dp[n];
    return 0;
}