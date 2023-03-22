#include<bits/stdc++.h>
#define int long long
using namespace std;

struct binomial{
    vector<int> fac;
    vector<int> invfac;
    vector<int> inv;
    int N;
    const int MOD_ = 1e9+7;

    binomial(int sz){
        fac.assign(sz+1,1);
        invfac.assign(sz+1,1);
        inv.assign(sz+1,1);
        N = sz;
    }

    void init(){
        for(int i=2 ; i<=N ; i++){
            fac[i] = (fac[i-1]*i)%MOD_;
        }
        for(int i=2 ; i<=N ; i++){
            inv[i] = inverse(i);
            invfac[i] = (inv[i]*invfac[i-1])%mod;
        }
    }

    int bin_exp(int a,int b){
        int ans = 1;
        while (b>0){
            if(b&1){
                ans = (ans * 1LL * a)%MOD_;
            }
            a = (a*1LL*a)%MOD_;
            b>>=1;
        }
        return ans;
    }

    int inverse(int n){
        return (bin_exp(n,MOD_-2));
    }

    int ncr(int n , int r){
        if(n<0 || r<0 || r>n) return 0;
        int ans = (fac[n]*invfac[n-r])%MOD_;
        ans = (ans*invfac[r])%MOD_;
        return ans;
    }

    int npr(int n , int r){
        if(n<0 || r<0 || r>n) return 0;
        int ans = (fac[n]*invfac[n-r])%MOD_;
        return ans;
    }
    
};

int32_t main(){
    const int N = 1e5+4;
    binomial b(N);
    b.init();
    cout<<b.ncr(4,2)<<endl;

    const int mod = 1e9+7;
    cout<<solve(1e15,100,mod)<<endl;
    return 0;
}