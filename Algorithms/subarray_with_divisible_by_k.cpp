#include<bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=QM0klnvTQzk

int32_t main(){
    int n = 7;
    int a[n]= {2,3,5,4,5,3,4};
    int k=7;
    // find subarray which sum is divisible by k;

    map<int,int> m;
    int sum=0;
    m[sum]++;
    int ans=0;
    for(int i=0 ;i<n;i++){
        sum+=a[i];
        int r = sum%k;
        if(r<0)r+=k;
        if(m.find(r)!=m.end()){
            ans+=m[r];
        }
        m[r]++;
    }
    cout<<ans<<endl;
    return 0;
}