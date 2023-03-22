#include<bits/stdc++.h>
using namespace std;

#define int long long int 

// point update and range query
struct BITpr{
    vector<int> bit;
    int n;

    BITpr(vector<int> &a){
        n = a.size();
        bit.resize(n+1,0ll);
        for(int i=0 ; i<n ; i++){
            add(i,a[i]);
        }
    }
    
    int low_bit(int n){
        return (n&(-n));
    }

    void add(int i,int x){
        for(++i;i <= n; i += low_bit(i)) bit[i] += x;
    }

    // prefix sum of i;
    int sum(int i){
        int res = 0;
        for(++i;i > 0;i -= low_bit(i)) res += bit[i];
        return res;
    }
 
    int sum(int l,int r){
        return (sum(r) - sum(l - 1));
    }

    void print(){
        int sz = bit.size();
        for(int i=0 ; i<sz ; i++){
            cout<<bit[i]<<" "<<i<<endl;
        }
    }
};

// range update and point query
struct BITrp{
    vector<int> bit;
    int n;

    BITrp(vector<int> &a){
        n = a.size();
        bit.resize(n+2,0ll);
        for(int i=0 ; i<n ; i++){
            range_add(i,i,a[i]);
        }
    }

    int low_bit(int n){
        return (n&(-n));
    }

    void add(int i,int x){
        for(++i;i <= n; i += low_bit(i)) bit[i] += x;
    }
    
    void range_add(int l, int r, int val){
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int i){
        int ans = 0;
        for (++i; i > 0; i -= low_bit(i)){
            ans += bit[i];
        }
        return ans;
    }
};


// range update and range query
struct BITrr{
    vector<int> bit1,bit2;
    int n;

    BITrr(vector<int> &a){
        n = a.size();
        bit1.resize(n+1,0ll);
        bit2.resize(n+1,0ll);
        for(int i=0 ; i<n ; i++){
            range_add(i,i,a[i]);
        }
    }

    int low_bit(int n){
        return (n&(-n));
    }

    void add(vector<int> &bit , int i,int x){
        for(++i;i <=n;i += low_bit(i)) bit[i] += x;
    }
    
    void range_add(int l, int r, int val) {
        add(bit1,l, val);
        add(bit1,r + 1, -val);
        add(bit2,l,val*(l-1));
        add(bit2,r+1,-val*r);
    }

    int sum(vector<int> &bit , int i){
        int ans = 0;
        for (++i; i > 0; i -= low_bit(i))
            ans += bit[i];
        return ans;
    }

    int prefix(int i){
        return (sum(bit1,i)*i - sum(bit2,i));
    }

    int range_query(int l,int r){
        return (prefix(r)-prefix(l-1));
    }
};

int32_t main(){
    
    // vector<int> a = {5,3,2,4,1};
    // int n = a.size();
    // BITpr bpr(a); 
    // for(int i=0 ; i<n ; i++){
    //     cout<<"i = "<<i<<" "<<bpr.sum(i)<<endl;
    // }
    // cout<<bpr.sum(0,2)<<endl;

    // BITrp brp(a);
    // brp.range_add(0,5,5);
    // for(int i=0 ; i<n ; i++){
    //     cout<<"i = "<<i<<" "<<brp.point_query(i)<<endl;
    // }

    // BITrr brr(a);
    // brr.range_add(0,5,5);
    // for(int i=0 ; i<n ; i++){
    //     cout<<"i = "<<i<<" "<<brr.range_query(i,i)<<endl;
    // }
    
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    BITpr b(a);
    b.print();

    return 0;
}