#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ;i<n;i++) cin>>a[i];
    
    vector<int> dp(n,1);
    for(int i=0 ;i<n;i++) dp[i]=a[i];

    for(int i=0 ;i<n;i++){
        for(int k=0 ;k<i;k++){
            if(a[k]<a[i])
                dp[i] = max(dp[k]+a[i] , dp[i]);
        }
    }
    int ans=0;
    for(int i=0 ;i<n;i++){
        ans =  max(ans,dp[i]);   
    }
    cout<<ans<<endl;
    
    return 0;
}