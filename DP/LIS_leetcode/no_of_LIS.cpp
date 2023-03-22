#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ;i<n;i++) cin>>a[i];
    vector<int> dp(n,1);
    vector<int> count(n,1);

    map<int,int> m;
    for(int i=0 ;i<n;i++){
        for(int k=0 ;k<i;k++){
            if(a[k]<a[i] && dp[i]<dp[k]+1){
                dp[i] = dp[k] + 1 ;
                count[i]=count[k];
            }
            else if(dp[i]==dp[k]+1){
                count[i]+=count[k];
            }
        }
    }

    int ans=0;
    for(int i=0 ;i<n;i++){
        ans = max(ans,dp[i]);
    }

    int res=0;
    for(int i=0 ;i<n;i++){
        if(ans==dp[i])
            res+=count[i];
    }
    
    cout<<res<<endl;
    return 0;
}