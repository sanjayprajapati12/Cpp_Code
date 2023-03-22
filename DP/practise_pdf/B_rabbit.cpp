
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
    string s;
    cin>>s;

    vector<int> dp(n+1,0);
    fo(i,1,n){
        if(s[i-1]=='w')
            dp[i]=-1;
        else if(s[i-1]=='"') dp[i]=1;
    }
    fo(i,2,n){
        if(dp[i]==-1) continue;
        int x=-1;
        for(int j=1 ; j<=5 ; j+=2){
            if((i-j)>0)
                x = max(x,dp[i-j]);
        }
        if(x==-1){
            dp[i]=-1;
        }
        else{
            dp[i]+=x;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}