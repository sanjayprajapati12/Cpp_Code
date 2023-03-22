#include<bits/stdc++.h>
using namespace std;


#define int long long int
#define INF 1e12

int MCM(int arr[], int i , int j ){
    if(i>=j) return 0;

    int mn = INF ;
    for(int k = i ; k<=(j-1) ; k++){
        int temp = MCM(arr,i,k) + MCM(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]) ;
        mn = min(mn,temp);
    }
    return mn;
}
    
int32_t main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ;i<n;i++) cin>>arr[i];

    // recursive
    int i=1; // M1 = a[1] X a[0] so we take i = 1
    int j=n-1;  
    cout<<MCM(arr,i,j)<<endl;

    // bottom-up DP
    vector<vector<int>> dp(n,vector<int> (n,INF));
    for (i = 1; i < n; i++)
        dp[i][i] = 0;
 
    // L is chain length.
    for (int L = 2; L < n; L++){
        for (int i = 1 , j = L ; j < n ; i++,j++){
            for (int k = i; k <= j - 1; k++){
                int temp = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                dp[i][j] = min(dp[i][j],temp);
            }
        }
    }

    cout<<dp[1][n - 1]<<endl;

    return 0;
}