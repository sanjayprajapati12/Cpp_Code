#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

int multiply(int a, int b) {
    int ans = 0;
    while (b) {
        if (b & 1) {
            ans += a;
            if (ans >= mod) {
                ans -= mod;
            }
        }

        a = (a << 1);
        if (a >= mod) {
            a -= mod;
        }
        b >>= 1;
    }
    return ans;
}

int32_t main(){
    cout<<multiply(1e15,1e17+1)<<endl; //6795545890343709585
    int n = 1e15;
    int m = 1e17 + 1;
    cout<<(n*m)%mod<<endl; // give wrong answer
    return 0;
}