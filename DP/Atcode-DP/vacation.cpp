
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
    int n;
    cin>>n;
    vector<tuple <int ,int , int >> v;

    fo(i,1,n){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }


    vector<int> dp(n+1,-INT_MAX);

    int x,y,z;
    tie(x,y,z) = v[0];
    dp[1] = max(x,y,z) ;
    int pre = dp[1];
    
    dp[2] = abs(a[2]- a[1]);
    fo(i,2,n){
        int p,q,r;
        tie(p,q,r) = v[i-1];
        
            if((i-j)>0)
                dp[i] = min ( dp[i] , dp[i-j] + abs(a[i] - a[i-j])) ;
        
        pre = dp[2]-dp[1];
    }
    cout<<dp[n];
    return 0;
}