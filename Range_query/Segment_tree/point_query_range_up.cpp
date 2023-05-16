#include<bits/stdc++.h>
using namespace std;

#define int long long int

int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}

// point query  , range update
struct segTree{
    // CONST and op
    int CONST = 0;
    int op(int a,int b){ return (a+b); }

    vector<int> tree;
    int n;
    segTree(int _n){
        n = _n;
        tree.resize(4*n,CONST);
    }

    void pull(int v){
        tree[v] = op(tree[2*v],tree[2*v+1]);
    }
    
    void update(int v, int start, int end, int l, int r,int new_value) {
        if(r<start || l>end) return;
        if (l<=start && r>=end) {
            tree[v] =op(tree[v],new_value);
            return;
        }
        int mid = (start + end)/2;
        update(v*2, start, mid, l, r , new_value );
        update(v*2+1, mid+1, end, l, r , new_value);
    }

    int query(int v, int start, int end, int id) {
        if(id<start || id>end) return CONST;
        if (start==end) {
            return tree[v];
        }
        int mid = (start + end)/2;
        int ans = CONST;
        ans = op(ans , query(v*2, start, mid, id));
        ans = op(ans , query(v*2+1, mid+1, end, id));
        return op(tree[v],ans);
    }

    void update(int l,int r,int new_value){
        update(1,0,n-1,l,r,new_value);
    }

    int query(int id){
        return query(1,0,n-1,id);
    }
};  

int32_t main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    segTree st(n);
    for(int i=0 ; i<n ;i++){
        cin>>a[i];
        st.update(i,i,a[i]);
    }

    while(q--){
        int t;
        cin>>t;
        if(t==2){
            int id;
            cin>>id;
            cout<<st.query(id)<<endl;
        }
        else{
            int l,r,new_value;
            cin>>l>>r>>new_value;
            r--;
            st.update(l,r,new_value);
        }
    }
    return 0;
}

