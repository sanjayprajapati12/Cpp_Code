#include<bits/stdc++.h>
using namespace std;


#define int long long int
#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define rfo(i,n,x) for(int i=n; i>=x;i--) 
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define p1(x)      cout<<x<<endl
#define p2(x,y)    cout<<x<<" "<<y<<endl
#define p3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<endl
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define mod 1000000007
#define INF 1e12

int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}
    
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin>>n;
    int W;
    cin>>W;
    int val[n],wt[n];
    for(int i=0;i<n;i++) cin>>val[i];
    for(int i=0;i<n;i++) cin>>wt[i];

         vector<vector<int>> dp(n+1,vector<int> (W+1,0));
            for(int i=1 ; i<=n ; i++){
                for(int j=1 ; j<=W ; j++){
                    if(wt[i-1]<=j)
                        dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i][j-wt[i-1]] );
                    else
                        dp[i][j] = dp[i-1][j];
                }   
            }
        
        cout<<dp[n][W]<<endl;
        
    return 0;
}