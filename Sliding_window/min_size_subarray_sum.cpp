#include<bits/stdc++.h>
using namespace std;

int32_t main(){

    int n,k;
    cin>>n>>k;
    int a[n];

    for(int i=0 ;i<n;i++) cin>>a[i];

    int ans = INT_MAX;
    int sum = 0;
    int i = 0;
    for(int j = 0; j < n; j++) {
        sum += a[j]; 

        while(sum > k) { 
            sum -= a[i]; 
            i++; 
        }

        if(sum == k) {
            ans = min(ans, j-i+1);
        }
    }
    if(ans==INT_MAX) ans=0;

    cout<<ans<<endl;
    return 0;
}