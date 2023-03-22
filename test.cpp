#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>//
//#include<ext/pb_ds/tree_policy.hpp>//
using namespace std;
//using namespace __gnu_pbds;//

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
// #define mod 1000000007
#define FILL(x,v) memset(x, v, sizeof(x))
#define PI 3.14159265358979323846
#define INF LLONG_MAX  //9.223372e+18
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;// 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif


void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}


int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}


int Multiply(int a, int b,int mod) {
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

vi a(601);
void Solve(int n, const int k,int mod) {
    if (n == 0) {
        a[0] = 1;
        return;
    }
 
    Solve(n / 2, k, mod);
    vi b = a;
    cout<<n<<endl;
    for (int i = 0; i <= k; i += 1) {
        int s = 0;
        for (int j = 0; j <= i; j += 1) {
            cout<<i<<" "<<j<<endl;
            s = (s + Multiply(a[j], a[i - j], mod));
            if (s >= mod) {
                s -= mod;
            }
        }
        b[i] = s;
    }
    
    for (int i = 0; i <= k; i += 1) {
        a[i] = b[i];
    }
 
    if (n % 2) {
        for (int i = k; i > 0; i -= 1) {
            a[i] += a[i - 1];
            if (a[i] >= mod) {
                a[i] -= mod;
            }
        }
    }
    // cout<<n<<endl;
    // for (int i = 0; i <= k; i += 1) {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
 
}

int32_t main(){
    fastio
    //cout<<setprecision(6)<<fixed<<ans<<endl;//
    //freopen( "input.txt" , "r" , stdin );//
    //freopen( "output.txt" , "w" , stdout );//
    
    // jaldi_karenge_jaldbaazi_nahi
    int t=1;
    // cin>>t;
    while(t--){
        int mod = 1e9+7;
        Solve(8,2,mod);
        fo(i,0,2){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}