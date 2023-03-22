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

    // Errichto solution
    int n;cin>>n;
    double a[n];
    for(int i=1 ;i<=n;i++) cin>>a[i];

    // dp[i]  --> probability that there are i heads so far 
    // tails = i - dp[i]
    vector<double> dp(n+1);
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j>=0 ;j--){
            dp[j] = (j==0 ? 0 : dp[j-1] * a[i])  + dp[j] * (1-a[i]);
        }
    }

    double ans = 0 ;
    for(int heads=0 ; heads<=n ; heads++){
        int tails = n - heads;
        if(heads > tails){
            ans += dp[heads];
        }
    }

    cout<<setprecision(10)<<ans<<endl;
    return 0;
}