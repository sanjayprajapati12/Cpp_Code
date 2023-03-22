#include<bits/stdc++.h>
using namespace std;

#define int long long int

int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}

// range query , point update 
struct segTree{
    // CONST and op
    int CONST = 0;
    int op(int a,int b){ return (a+b); }

    vector<int> tree;
    int n;
    segTree(int _n){
        n = _n;
        tree.resize(4*n);
    }

    void pull(int v){
        tree[v] = op(tree[2*v],tree[2*v+1]);
    }
    
    int query(int v, int start, int end, int l, int r) {
        if(r<start || l>end) return CONST;
        if (l<=start && r >= end) {
            return tree[v];
        }
        int mid = (start + end)/2;
        int ans = CONST;
        ans = op(ans , query(v*2, start, mid, l, r) ) ;
        ans = op(ans , query(v*2+1, mid+1, end, l, r) );
        return ans;
    }

    void update(int v, int start, int end, int id , int new_val) {
        if(id<start || id>end) return;
        if (start==end) {
            tree[v] = new_val;
            return;
        }
        int mid = (start + end)/2;
        update(v*2, start, mid, id ,new_val);
        update(v*2+1, mid+1, end, id ,new_val);
        pull(v);
    }

    int query(int l,int r){
        return query(1,0,n-1,l,r);
    }
    void update(int id,int value){
        update(1,0,n-1,id,value);
    }
};  

int32_t main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    segTree st(n);
    for(int i=0 ; i<n ;i++){
        cin>>a[i];
        st.update(i,a[i]);
    }
    while(q--){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            st.update(l,r);
        }
        else{
            r--;
            cout<<st.query(l,r)<<endl;
        }
    }
    return 0;
}
