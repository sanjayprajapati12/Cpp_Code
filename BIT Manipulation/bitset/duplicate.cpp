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

    bitset<1000001> visited;
    int t;cin>>t;
    while(t--){
        int x;
        cin>>x;
        visited[x]=true;
    }
    cout<<visited.count()<<endl;
    
    return 0;
}