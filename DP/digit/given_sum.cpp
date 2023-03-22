#include<bits/stdc++.h>
using namespace std;
// always take a pos variable --> it is very easy to handle and also you can think about iterative 
// number    =  4 5 2 1 7 5
// position  =  1 2 3 4 5 6
// so when position is greater than n(number of digit) then return accourding to problem 

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

int cntWithZero(int pos,int n,int sum){
    if(pos>n){
        if(sum==0) return 1;
        return 0;
    }

    if(sum==0) return 1;

    int ans =0;
    fo(i,0,9){
        if(sum-i>=0){
            ans+= cntWithZero(pos+1,n,sum-i);
        }
    }

    return ans;
}

// if we want to find (3,5) --> (2,4) + (2,3) + (2,2) + (2,1) +  (2,0) 
int cnt(int pos , int n,int sum){
    int ans = 0 ;
    fo(i,1,9){
        if(sum-i>=0){
            ans += cntWithZero(pos+1,n,sum-i);
        }
    }
    return ans;
}

int32_t main(){

    int n,sum;
    cin>>n>>sum;
    // n is no. of digit a number have
    cout<<cnt(1,n,sum)<<endl;

    // bottom-up dp 
    // dp[i][j] -> means we fill 0 to ith position from left
    // number = 234 , then 4 is at position 1 , 3 is at position 2 
    vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
    
    for(int i=0; i<= min(sum,9ll) ;i++){
        dp[1][i]=1;
    }
     
    int temp;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=sum;j++){
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
    
    cout<<dp[n][sum]<<endl;

    return 0;
}