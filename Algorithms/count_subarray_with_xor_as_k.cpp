#include<bits/stdc++.h>
using namespace std;

// T -> O(N*log(N))

int32_t main(){
    int n;cin>>n;
    int k;cin>>k;
    int a[n];

    for(int i=0 ;i<n;i++)cin>>a[i];

    int x = 0;
    int ans=0;
    map<int,int> m;

    for(int i=0 ; i<n ; i++){
        x = x^a[i];
        if(x==k)ans++;

        int y = x^k;
        if(m.find(y)!=m.end()){
            ans+=m[y];
        }
        m[x]++;
    }
    
    cout<<ans<<endl;
    return 0;
}