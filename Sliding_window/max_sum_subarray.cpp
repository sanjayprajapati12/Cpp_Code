#include<bits/stdc++.h>
using namespace std;


#define int long long int

int32_t main(){
    int n,k;
    cin>>n>>k;
    int a[n];

    for(int i=0 ;i<n;i++) cin>>a[i];

    int ans = 0;
    for(int i=0 ;i<k;i++)  ans+=a[i];

    int cur = ans ;
    for(int j=k ; j<n ;j++){
        cur += a[j] - a[j-k];
        ans  = max ( ans , cur );
    }
    
    cout<<ans<<endl;
    return 0;

}