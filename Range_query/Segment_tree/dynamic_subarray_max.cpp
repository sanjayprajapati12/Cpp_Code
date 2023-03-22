#include<bits/stdc++.h>
using namespace std;
#define int long long int 

struct segTree{
    struct node{
        int pref, suf, val, sum;
    };  
    int N;
    int neutral;
    vector<node> t;
    segTree(int _N){
        N = _N;
        t.resize(4 * N);
        for(int i=0 ; i<t.size();i++){
            t[i] = {0, 0, 0, 0};
        }
    }

    node merge(node a, node b) {
        node c;
        c.pref = max(a.pref, a.sum + b.pref);
        c.suf = max(b.suf, b.sum + a.suf);
        c.val = max({a.val, b.val, a.suf + b.pref});
        c.sum = a.sum + b.sum;
        return c;
    }
 
    void update(int i, int l, int r, int pos, int val) {
        if(l > pos || r < pos) return;
        if(l == pos && r == pos) {
            t[i].pref = t[i].suf = t[i].val = t[i].sum = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(2 * i, l, mid, pos, val);
        update(2 * i + 1, mid + 1, r, pos, val);
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }

    node query(int i, int l, int r, int tl, int tr) {
        if(l > tr || r < tl) return {0, 0, 0, 0};
        if(l >= tl && r <= tr) return t[i];
        int mid = (l + r) >> 1;
        return merge(query(2 * i, l, mid, tl, tr), query(2 * i + 1, mid + 1, r, tl, tr));
    }
 
    void update(int pos, int val) {
        update(1, 0, N - 1, pos, val);
    }

    node query(int l, int r) {
        return query(1, 0, N - 1, l, r);
    }

};
    
int32_t main(){
    int n,m;
    cin>>n>>m;
    segTree st(n);
    vector<int> a(n);
    for(int i=0 ;i<n ;i++){
        cin>>a[i];
        st.update(i,a[i]);
    }
    cout<<max(0LL,st.query(0,n-1).val)<<endl;
    while(m--){
        int i,x;
        cin>>i>>x;
        st.update(i,x);
        cout<<max(0LL,st.query(0,n-1).val)<<endl;
    }
    return 0;
}