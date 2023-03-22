#include<bits/stdc++.h>
#define int long long
using namespace std;
// why needed -> if we want to (25/5)%m then it gives us error ;
// so we have something that we can replace with 5 , so we calculate modulo_inverse of 5 and than compute
// for understanding purpose you can do (a*modulo_inv(a))%m which gives you 1


// (a*modulo_inv(a))%m is nothing but (a/a)%m

const int mod = 1e9+7;

int bin_exp(int a,int b) {
       int ans = 1;
    while (b>0){
        if(b&1){
            ans = (ans * 1LL * a)%mod;
        }
        a = (a*1LL*a)%mod;
        b>>=1;
    }
    return ans;
}

int32_t main(){

    for(int i=1;i<20;i++){
        cout<<(i*bin_exp(i,mod-2))%mod<<" ";
    }
    cout<<endl;

    int inv[10000];
    inv[1] = 1;
    for(int i = 2; i < 20; ++i)
        inv[i] = mod - (mod/i) * inv[mod%i] % mod;
        
    for(int i = 1; i < 20; ++i)
        cout<<(i*inv[i])%mod<<" ";

    return 0;
}