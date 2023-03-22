#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}
    
struct segTree{
    int CONST = 0;
    vector<int> tree;
    int n;
    int op(int a,int b){ return (a+b); }
 
    segTree(vector<int> &a){
        n = a.size();
        tree.resize(2*n);
        build(a);
    }

    void build(vector<int> &arr){
        for(int i=0; i<n; i++){
            tree[n+i] = arr[i];
        }
        for(int i = n - 1; i >= 1; --i)	{
            tree[i] = op(tree[2*i] , tree[2*i+1]);
        }
    }

    void update(int id, int value){
        tree[n+id] = value;
        for(int j = (n+id)/2 ; j>=1 ; j/=2){
            tree[j] = op(tree[2*j] , tree[2*j+1]);
        }
    }
    
    int query(int l, int r){
        int res = CONST;
        for(l+=n, r+=n+1; l<r; l>>=1, r>>=1){
            if(l&1) res = op(res, tree[l++]);
            if(r&1) res = op(res, tree[--r]);
        }
        return res;
    }
};

int32_t main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	segTree st(a);

	// these query give ans of (a[1]...a[3])
	cout << st.query(1, 3)<<endl;
	
	// a[2] = 1 ; 
	st.update(2, 1);
	
	// these query give ans of (a[1]...a[4])
	cout << st.query(1, 3)<<endl;
    return 0;
}