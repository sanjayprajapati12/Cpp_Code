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
    
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    fo(i,0,n-1){
        cin>>a[i];
        sum+=a[i];
    }
    
    vector<vector<int>> dp(n,vector<int> (n,0));

    // my solution
    fo(l,0,n-1){
        for(int i=0,j=l ; j<n ; i++,j++){
            if(l==0){
                dp[i][j]=a[i];
            }
            else if(l==1){
                dp[i][j] = max(a[i],a[j]);
            }
            else{
                int x = a[i] + min(dp[i+2][j],dp[i+1][j-1]);
                int y = a[j] + min(dp[i+1][j-1] , dp[i][j-2]);
                dp[i][j] = max(x,y);
            }
        }
    }
    cout<<2*dp[0][n-1]-sum<<endl;
    
    // Errichto solution
    vector<vector<int>> DP(n,vector<int> (n,0));
    for(int L = n-1 ; L >=0 ; L--){
        for(int R=L ; R<n ; R++){
            if(L==R){
                DP[L][R] = a[L];
            }
            else{
                DP[L][R] = max( a[L] - DP[L+1][R] , a[R] - DP[L][R-1]);
            }
        }
    }
    
    cout<<DP[0][n-1];
    return 0;
}