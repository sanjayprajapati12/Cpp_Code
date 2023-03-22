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
        
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    fo(i,0,n-1){
        cin>>a[i];
    }
    
    // dp[i] = true means the first player win if there are i stones remaining

    vector<bool> dp(k+1,false);
    for(int i = 0 ; i<=k ; i++){
        for(int x : a){
            if((i>=x) && dp[i-x]==false){
                dp[i] = true;
            }
        }
    }

    if(dp[k])cout<<"First"<<endl;
    else cout<<"Second"<<endl;

    return 0;
}