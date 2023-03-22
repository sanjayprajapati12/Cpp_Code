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

int32_t main(){

    string s;
    cin>>s;
    int n = s.length();
    int m = (10*n) + 1;
    // bottom-up dp 
    vector<vector<int>> dp(n+1,vector<int> (m,0));
    
    for(int i=0;i<=9 && i<=m;i++){
        dp[1][i]=1;
    }
     
    int temp;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=m;j++){
            temp = 0;
            // here k is start from 0 ;
            for(int k=0;k<=9;k++){
                // for i==n we don't want to take k==0 --> 00,01,02,03,04,05,06,07,08,09 is not 2-digit no. 
                if(i==n && k==0) continue;
                if(j-k>=0){
                    temp += dp[i-1][j-k];
                }
                else
                    break;
            }
            dp[i][j] = temp;
        }
    }
     
    cout<<dp[n][m]<<endl;

    return 0;
}