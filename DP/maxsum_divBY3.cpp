// u can solve form total sum of array and than see that if there any sum which is div by 3
// above method throw TLE

// below metod is usefull to solve
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ;i<n;i++)cin>>arr[i];
        vector<int> dp(3,0);
        int x,y,z;
        for(int i=0; i<n; i++) {
            x = dp[0] + arr[i];
            y = dp[1] + arr[i];
            z = dp[2] + arr[i];
            dp[x%3] = max(dp[x%3], x);
            dp[y%3] = max(dp[y%3], y);
            dp[z%3] = max(dp[z%3], z);
        }

        cout<<dp[0];
    return 0;
}