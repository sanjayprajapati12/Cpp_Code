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

int arr[100];
int dp[11][100][2];

// n=469 than , a[1]=4 , a[2]=6 , a[3]=9 
int digitSum(int pos,int n,int sum,bool flag){
    if(pos>n) return sum;

    if(dp[pos][sum][flag]!=-1) return dp[pos][sum][flag];

    int limit = 9;
    if(!flag) limit = arr[pos];

    int ans=0;
    // till limit-1 , there is no problem , so give true to next recursion
    fo(i,0,limit-1){
        ans+=digitSum(pos+1,n,sum+i,true);
    }

    // at limit give flag's value to next recursion
    ans+=digitSum(pos+1,n,sum+limit ,flag);

    // return ans;
    return dp[pos][sum][flag]=ans;
}

int32_t main(){

ios_base::sync_with_stdio(false);
cin.tie(nullptr); cout.tie(nullptr);
    
    
    int m;
    cin>>m;
    
    // store pos into array
    int digit = log10(m)+1;
    int n=digit;
    int t=m;
    while(t){
        arr[digit] = t%10;
        t/=10;
        digit--;
    }

    memset(dp,-1,sizeof dp);
    // false means there is certain limit [ not 9 but the a[pos] ] 
    cout<<digitSum(1,n,0,false); 
    return 0;
}