#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>//
//#include<ext/pb_ds/tree_policy.hpp>//
using namespace std;
//using namespace __gnu_pbds;//


#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif


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
#define mod 1000000007
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
    
int32_t main(){
    fastio
    //cout<<setprecision(6)<<fixed<<ans<<endl;//
    //freopen( "input.txt" , "r" , stdin );//
    //freopen( "output.txt" , "w" , stdout );//
    
    // jaldi_karenge_jaldbaazi_nahi
    int t=1;
    // cin>>t;
    while(t--){
        

        int n,q;
        cin>>n>>q;
        vi a(n);
        cin>>a;
        vector<pair<pair<int,int>,int>> qq;
        fo(i,0,q-1){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            qq.push_back(make_pair(make_pair(l,r),i));
        }

        
		
		int block_size = sqrtl(n);

        sort(all(qq),[&](auto a,auto b){
            if(a.first.first/block_size != b.first.first/block_size){
                return a.first.first/block_size < b.first.first/block_size;
            }
            else{
                return a.first.second < b.first.second;
            }
        });

        const int N = 1e6+10; // need to change
        vector<int> mp(N,0);
		
        int global_ans = 0 ;

		// change 
        auto add = [&](int i){
            global_ans -= (mp[a[i]]*mp[a[i]]*a[i]);
            mp[a[i]]++;
            global_ans += (mp[a[i]]*mp[a[i]]*a[i]);
        };

		// change
        auto remove = [&](int i){
            global_ans -= (mp[a[i]]*mp[a[i]]*a[i]);
            mp[a[i]]--;
            global_ans += (mp[a[i]]*mp[a[i]]*a[i]);
        };

        vi ans(q);
        int mo_left = 0 ;
        int mo_right = -1;

        fo(i,0,q-1){
            int l = qq[i].first.first;
            int r = qq[i].first.second;
            int id = qq[i].second;

            while(mo_right>r){
                remove(mo_right);
                mo_right--;
            }

            while(mo_left>l){
                mo_left--;
                add(mo_left);
            }
            
            while(mo_right<r){
                mo_right++;
                add(mo_right);
            }

            while(mo_left<l){
                remove(mo_left);
                mo_left++;
            }

            ans[id] = global_ans;
        }

        for(auto &x:ans){
            cout<<x<<endl;
        }

    }
    return 0;
}