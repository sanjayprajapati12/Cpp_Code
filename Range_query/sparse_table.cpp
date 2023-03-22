#include<bits/stdc++.h>
using namespace std;


#define int long long
#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define rfo(i,n,x) for(int i=n; i>=x;i--) 
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define minv(v)      *min_element(v.begin(), v.end())
#define maxv(v)      *max_element(v.begin(), v.end())
#define print(v)     for(auto k : v) cout<<k<<" "
#define p1(x)      cout<<x<<endl
#define p2(x,y)    cout<<x<<" "<<y<<endl
#define p3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<endl
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define mod 1000000007
#define INF 1e12


// mat[l][i] --> this store ans for starting from index i and length 2^l  
// all the lenght are power of 2 
// instead of storing length , we store store power

// O(n*log(n) + q)
// For max , min , gcd  --> overlapping doesn't even matter

// template of turist 
template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable{
 public:
  int n;
  vector<vector<T>> mat;
  F func;
 
  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = (int)log2(n)+1;
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
 
  T query(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = (int)log2(to-from+1);
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }

    void test(string s){
        cout<<s<<endl;
        int max_log = (int)log2(n)+1;
        for(int k=0 ; k<max_log ; k++){
            for(int i=0 ; i<=n-(1<<k) ;i++){
                cout<<mat[k][i]<<" ";
            }
            cout<<endl;
        }
    }
};

int32_t main(){
    

    int n;cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
       cin>>v[i];
    }


    int q;
    cin>>q;
    SparseTable<long long> smin(v, [&](long long i, long long j) { return min(i, j); });
    while(q--){
        int L,R;
        cin>>L>>R;
        cout<<smin.query(L,R)<<endl;
    }

    return 0;
}