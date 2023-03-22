#include<bits/stdc++.h>
using namespace std;

// given a set , count how many subsets have sum greater than or equal to given target 


int32_t main(){

    int n,target;
    cin>>n>>target;

    int a[n] ;
    for(int i=0 ;i<n;i++)cin>>a[i];
    
    // tc --> (2^n*n);

    int ans=0;
    for(int mask=0 ; mask<(1<<n) ;mask++){
        int sum=0 ;
        for(int bit=0 ;bit<n;bit++){
            if(mask&(1<<bit)!=1){
                sum += a[bit];
            }
        }

        if(sum>=target){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}