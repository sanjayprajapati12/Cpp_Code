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

int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}
    
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr); cout.tie(nullptr);
    
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
 
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
   
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;                
    }
 
    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;                
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = min(min(dp[i - 1][j] + 1 , dp[i][j - 1] + 1), dp[i - 1][j - 1] +( (s1[i - 1] == s2[j - 1]) ? 0:1) );    
        }
    }
 
    cout<<dp[n][m]<<endl;
    return 0;
}