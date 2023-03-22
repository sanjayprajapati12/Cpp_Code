#include<bits/stdc++.h>
using namespace std;


#define int long long int

int32_t main(){

    int n;
    cin>>n;
    int a[n];
    // 1-indexed array 
    int check=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        check+=a[i];
    }
    if(n==2){
        cout<<abs(a[1]-a[2])<<endl;
        return 0;
    }
        int sum = check/2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0 ; i<=n ; i++){
            dp[i][0]=1;
        }

        for(int i=1 ;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(a[i]<=j)  
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        while(sum){
            if(dp[n][sum]) {
                cout<<(check - 2*sum)<<endl;
                break;
            }
            sum--;
        }
    return 0;
}
//  { 3, 1, 4, 2, 2, 1 }