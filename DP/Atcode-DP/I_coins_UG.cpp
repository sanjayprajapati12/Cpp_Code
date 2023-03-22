#include<bits/stdc++.h>
using namespace std;


#define int long long int
#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define rfo(i,n,x) for(int i=n; i>=x;i--) 
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define minv(v)      *min_element(v.begin(), v.end())
#define maxv(v)      *max_element(v.begin(), v.end())
#define print(v)     for(auto k : v) cout<<k<<" "
#define p1(x)      cout<<x<<endl
#define p2(x,y)    cout<<x<<" "<<y<<endl
#define p3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<endl
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define mod 1000000007
#define INF 1e12

int32_t main(){

    int n;cin>>n;
    double a[n];
    // a[i] -> probability that heads occur
    // find the probability of having more heads than tails
    for(int i=0 ;i<n;i++) cin>>a[i];

    // dp[i][j]  --> i+1 tosses and j heads are occur
    vector<vector<double>> dp(n,vector<double> (n+1,0));
    dp[0][1] = a[0];   // 1 toss and head occur 
    dp[0][0] = 1 - a[0]; // 1 toss and tail occur
    
    for(int i=1 ;i<n;i++){
        for(int j=0 ; j<=n ;j++){
            // tails
            dp[i][j] += (1-a[i])*dp[i-1][j];
            // haids
            if(j)
                dp[i][j] += (a[i])*dp[i-1][j-1];
        }
    }

    double ans =0;
    for(int i=n/2 + 1 ; i<=n; i++){
        ans+= dp[n-1][i];
    }
    
    cout<<setprecision(10)<<ans<<endl;
    return 0;
}