#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define mod 1000000007
    
int32_t main(){

    vector<vector<int>> dp(51,vector<int> (51,0));
    dp[2][3]=1;
    dp[3][2]=1;

    fo(i,1,50){
        fo(j,1,50){
            if((i-2)>0 && (j-1)>0) dp[i][j] +=dp[i-2][j-1];
            if((j-2)>0 && (i-1)>0) dp[i][j] +=dp[i-1][j-2];
        }
    }

    // print all the cases 
    
    // fo(i,1,50){
    //     fo(j,1,50)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }


    int n,m;
    cin>>n>>m;
    cout<<dp[n][m]<<endl;
    return 0;
}