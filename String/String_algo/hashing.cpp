#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 9;


int bin_exp(int a,int b,int c) {
    int ans = 1;
    while (b>0){
        if(b&1)
            ans = (ans * 1LL * a)%c;
        a = (a*1LL*a)%c;
        b>>=1;
    }
    return ans%c;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
const int N = 1e6 + 9;
pair<int, int> pw[N], ipw[N];
void prec() {

    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = bin_exp(p1, MOD1 - 2, MOD1);
    ip2 = bin_exp(p2, MOD2 - 2, MOD2);
    ipw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }
}

struct Hashing {
    int n;
    string s; // 0 - indexed
    vector<pair<int, int>> hs; // 1 - indexed

    Hashing(string _s) {
        n = _s.size();
        s = _s;
        hs.emplace_back(0LL, 0LL);
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * (s[i]-'a'+1) % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * (s[i]-'a'+1) % MOD2) % MOD2;
            hs.push_back(p);
        }
    }

    pair<int, int> get_hash(int l, int r) { // 1 - indexed
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l-1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l-1].second % MOD2;
        return ans;
    }

    pair<int, int> get_hash() {
        return get_hash(1, n);
    }
};


int32_t main(){
    prec();
    string s,pattern;
    cin>>s>>pattern;
    int n = s.length();
    int m = pattern.length();
    Hashing hash_pattern(pattern);
    Hashing hash_main(s);

    int start = 0 ,end = m-1;
    vector<int> ans;
    while(end<n){
        if(hash_main.get_hash(start+1,end+1)==hash_pattern.get_hash()){
            ans.push_back(start);
        }
        end++;
        start++;
    }
    for(auto &x:ans){
        cout<<x<<endl;
    }

    return 0;
}