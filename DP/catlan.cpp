#include<bits/stdc++.h>
using namespace std;
// unbounded knapsack

#define int long long int

int32_t main(){

    int n;
    cin>>n;
    
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
      
    for(int i=2 ;i<=n;i++){
        int inside = i - 1;
        int outside = 0 ; 
        while(inside >= 0 ){
            dp[i] += dp[inside]* dp[outside];
            inside--;
            outside++;
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}