#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int cost[21][21];
int dpr[21][1<<21];

// jth job we have to assing , people we have , total people .
int recurance(int j , int mask , int &n){
    if(j==n)return 0;

    if(dpr[j][mask]!=-1)return dpr[j][mask];

    int ans = INT_MAX;
    for(int i=0 ; i<n ;i++){
        if(mask & (1<<i)){
            ans = min(ans,cost[i][j] + recurance(j+1 , (mask ^ (1<<i)) , n));
        }
    }
    return dpr[j][mask] = ans;
}

int32_t main(){

    int n;cin>>n;
    memset(dpr,-1,sizeof dpr);
    for(int i=0 ; i<n ;i++){
        for(int j=0 ;j<n ;j++){
            cin>>cost[i][j];
        }
    }

    // recurance
    cout<<recurance(0,(1<<n)-1 , n)<<endl;

    // bottom-up approch
    vector<int> dp(1<<n,INF);
    // base case
    // dp[i] means what is the min cost to take (no. of ones in i)'s people
    dp[0]=0;

    for(int mask=0 ; mask< (1<<n) ; mask++){
        int no = 0 ,temp=mask;
        while(temp){
            no += temp%2;
            temp/=2;
        }

        for (int bit = 0; bit < n; bit++){
            if((mask&(1<<bit)) == 0){
                int newMask = (mask | (1<<bit));
                dp[newMask] = min(dp[newMask] , dp[mask] + cost[no][bit]);
            }
        }
        
    }

    cout<<dp[(1<<n)-1]<<endl;   

    return 0;
}