#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>//
#include<ext/pb_ds/tree_policy.hpp>//
using namespace std;
using namespace __gnu_pbds;//


#define int long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define rfo(i,n,x) for(int i=n; i>=x;i--) 
#define kill(x) cout<<x<<endl;continue;
#define OUTPUT(x) cout << (x ? "YES" : "NO")<<endl;
#define Output(x) cout << (x ? "Yes" : "No")<<endl;
#define output(x) cout << (x ? "yes" : "no")<<endl;
#define minv(v)    *min_element(v.begin(), v.end())
#define maxv(v)    *max_element(v.begin(), v.end())
#define sumv(v)    accumulate(v.begin(), v.end(), 0LL)
#define print(v)   for(auto k : v) cout<<k<<" "
#define all(v)   v.begin(),v.end()
#define rall(v)   v.rbegin(),v.rend()
#define p1(x)      cout<<x<<endl
#define p2(x,y)    cout<<x<<" "<<y<<endl
#define p3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<endl
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define vvi vector<vector<int>>
// #define m 1000000007
#define FILL(x,v) memset(x, v, sizeof(x))
#define PI 3.14159265358979323846
#define INF LLONG_MAX  //9.223372e+18
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;// 

struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
        size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}


int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}



// yehi hai sab ku6 
using u64 = uint64_t;
using u128 = __uint128_t;
 
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
 
bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;
 
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
 
    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

int32_t main(){
    fastio
    //cout<<setprecision(6)<<fixed<<ans<<endl;//
    //freopen( "input.txt" , "r" , stdin );//
    //freopen( "output.txt" , "w" , stdout );//
    
    // jaldi_karenge_jaldbaazi_nahi
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}