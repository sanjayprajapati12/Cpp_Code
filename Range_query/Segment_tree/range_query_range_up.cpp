#include<bits/stdc++.h>
using namespace std;

#define int long long int 
#define INF 1e18;

struct segTree{
    // change const and lazy_const 
    int CONST = 0;
    int lazy_CONST = 0;
    vector<int> tree,lazy;
    int n;

    // change operation 
    int op(int a,int b){ return (a+b); }

    segTree(int sz){
        n = sz;
        tree.resize(4*n+1,CONST); // change if needed
        lazy.resize(4*n+1,lazy_CONST);
    }

    void pull(int node){
        tree[node] = op(tree[2*node],tree[2*node+1]);
    }

    void push(int node,int start,int end)
    {
        if(lazy[node]==lazy_CONST){
            return ;
        }
        
        
        int len = end - start + 1;
        int up = lazy[node];

        tree[node] += up*len; // change this
        if(start!=end){
            // change this 
            lazy[2*node]+=up;  
            lazy[2*node+1]+=up;
        }
        lazy[node] = lazy_CONST ;
    }

    void updateRange(int node, int start, int end, int l, int r, int val){
        push(node,start,end);
    
        if(start > end or start > r or end < l)return;

        if(start >= l and end <= r){
            lazy[node] += val;  // change this
            push(node,start,end);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(node*2, start, mid, l, r, val);        
        updateRange(node*2 + 1, mid + 1, end, l, r, val);
        pull(node);
    }

    int queryRange(int node, int start, int end, int l, int r){
        push(node,start,end);

        if(start > end or start > r or end < l)
            return CONST;         
        if(start >= l and end <= r)             
            return tree[node];
        
        int mid = (start + end) / 2;
        int left = queryRange(node*2, start, mid, l, r);         
        int right = queryRange(node*2 + 1, mid + 1, end, l, r); 
        return op(left , right);
    }

    void update(int l,int r , int v){
        updateRange(1,0,n-1,l,r,v);
    }

    int query(int l,int r){
        return queryRange(1,0,n-1,l,r);
    }
};

int32_t main(){
    int n,q;
    cin>>n>>q;
    segTree st(n);
    while(q--){
        int type;cin>>type;
        if(type==1){
            int l,r,v;
            cin>>l>>r>>v;
            r--;
            st.update(l,r,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            r--;
            cout<<st.query(l,r)<<endl;
        }
    }

    return 0;
}