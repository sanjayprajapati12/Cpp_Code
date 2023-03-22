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
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define mod 1000000007
#define INF 1e12

int getSum(int pos,int n,int sum){
    if(pos>n) return sum;

    int ans=0;
    fo(i,0,9){
        ans += getSum(pos+1,n,sum+i);
    }
    return ans;
}

int32_t main(){

ios_base::sync_with_stdio(false);
cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin>>n;
    // n is no. of digit a number have
    cout<<getSum(1,n,0)<<endl;

    // from getSum call we can't   calculate digitSum from 1 to 345 
    // so we have to do some modification 

    
    return 0;
}