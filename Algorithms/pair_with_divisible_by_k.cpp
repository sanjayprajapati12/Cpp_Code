#include<bits/stdc++.h>
using namespace std;
// not solved
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

int32_t main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0 ;i<n;i++){
        cin>>a[i];
    }
    // find pair which product is divisible by k;

    // map<reminder,freq>
    map<int,int> m;
    int ans=0;
    for(int i=0 ;i<n;i++){
        int r = a[i]%k;
        if(r<0)r+=k;

        if(r!=0){
            if(k%r==0){
                if(m.find(k/r)!=m.end()){
                    ans+=m[k/r];
                }
            }
        }
        else{
            if(m.find(r)!=m.end()){
                ans+=m[r];
            }
        }
        m[r]++;
    }
    int p=0;
    if(m.find(0)!=m.end()){
        int z=m[0];
        p +=  z*(2*n - (z+1))/2;
    }
    cout<<ans+p<<endl;

    return 0;
}