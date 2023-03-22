// boring number is the number in which all odd position contains odd digit
// and even position contains even digit 

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

string arr,all;

int solve(int pos,int n,bool even , bool leading , bool flag,string &tight){
    if(pos>n) return 1;

    int limit = 9;
    if(!flag) limit = (tight[pos-1]-'0') ;
    int ans = 0 ; 
    if(!even){
        if(leading==1){
            ans+= solve(pos+1,n,0,1,false,tight);
        }

        for(int i=1 ; i<limit ; i+=2){
            ans+= solve(pos+1,n,1,0,true,tight);
        }
        if(limit&1){
            ans+=solve(pos+1,n,1,0,false,tight);
        }
    }
    else{ 
        for(int i=0 ; i<limit ; i+=2){
            ans+= solve(pos+1,n,0,0,true,tight);
        }
        if(limit%2==0){
            ans+=solve(pos+1,n,0 ,0,false,tight);
        }
    }
    return ans;
}

int32_t main(){

ios_base::sync_with_stdio(false);
cin.tie(nullptr); cout.tie(nullptr);
    
    
    int l,r;
    cin>>l>>r;
    l--;
    all = to_string(l);
    arr = to_string(r);
    int n = arr.length();
    int m = all.length();

    int big = solve(1,n,false,true,false,arr);
    int small = solve(1,m,false,true,false,all);
    cout<<big-small<<endl;  
    return 0;
}