#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    int a[n];

    // array contains only 1 and 0
    for(int i=0 ;i<n;i++)cin>>a[i];

    int i=-1,j=0;
    int cnt=0,ans=0;
    while(j<n){
        if(a[j]==0){
            cnt++;
        }
        while(cnt>k){   
            i++;
            if(a[i]==0)cnt--;
        }
        ans = max(ans,j-i);
        j++;
    }
    cout<<ans<<endl;

    return 0;
}