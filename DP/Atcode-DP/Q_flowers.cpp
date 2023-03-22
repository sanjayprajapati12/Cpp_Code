#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){

    int n;cin>>n;
    vector<int> h(n),a(n);
    for(auto &x:h)cin>>x;
    for(auto &x:a)cin>>x;

    vector<int> tmp;
    int ans = a[0];
    tmp.push_back(h[0]);

    for(int i = 1 ; i<n;i++){
        if(tmp.back()<h[i]){
            ans += a[i];
            tmp.push_back(h[i]);
        }
        else{
            int id = lower_bound(tmp.begin(),tmp.end() , h[i]) - tmp.begin();
            ans += a[id];
            tmp[id] = h[i];
            ans += a[i];
        }
    }
    for(auto &x:tmp){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
    
    return 0;
}