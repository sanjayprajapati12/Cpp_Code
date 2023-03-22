#include<bits/stdc++.h>
// #define ll long long
using namespace std;
const int mod = 1e9+7;

int bin_exp(int a,int b,int c=mod) {
    int ans = 1;
    while (b>0){
        if(b&1)
            ans = (ans * 1LL * a)%c;
        a = (a*1LL*a)%c;
        b>>=1;
    }
    return ans;
}

// same as above 
int bin_pow(int a,int b){
    int ans = 1LL;
    while(b>0){
        if(b&1){
            ans = (ans*a)%mod;
            b--;
        }
        else{
            a = (a*a)%mod;
            b/=2;
        }
    }
    return ans;
}

int main(){
    int n = bin_exp(2,60) - 2;
    cout<<(bin_exp(4,n)*6)%mod; 
    return 0;
}