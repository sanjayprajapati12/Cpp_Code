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
#define M 1000000007

// remaining

int bin_exp(int a,int b) {
       int ans = 1;
    while (b>0){
        if(b&1)
            ans = (ans * 1LL * a);
        a = (a*1LL*a);
        b>>=1;
    }
    return ans;
}

int32_t main(){
    int n;
    cin>>n;

    vector<int> dp(n+1,0);
    dp[0] =1;
    dp[1] = 3;
    for(i,2,n){
        dp[i] = 3*dp[i-1] - bin_exp(3,i-2);
    }

    for(i,0,n)
        cout<<dp[i]<<" ";
    return 0;
}