#include<bits/stdc++.h>
using namespace std;

#define int long long int 
#define INF 1e18;


// tc -> O(Q*sqrt(n)+U) Q=query , U=update  update point 
// tc -> O((Q+U)*sqrt(n)) Q=query , U=update  update range

// point update and range query

struct sqrt_decomposition{
    int CONST = 0;
    vector<int> b;
    int n,len;
    int op(int a,int b){ return (a+b); }

    sqrt_decomposition(vector<int> &a){
        n = a.size();
        len = (int)sqrt(n)+1;
        b.resize(len);
        for(int i=0 ; i<n ;i++){
            b[i/len] = op(b[i/len],a[i]);
        }
    }

    int query(vector<int> &a ,int l, int r) {
        assert(l<=r);
        int sum = 0;
        int c_l = l/len,   c_r = r/len;
        if (c_l == c_r)
            for (int i=l; i<=r; ++i)
                sum = op(sum,a[i]);
        else {
            for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                sum = op(sum,a[i]);
            for (int i=c_l+1; i<=c_r-1; ++i)
                sum = op(sum,b[i]);
            for (int i=c_r*len; i<=r; ++i)
                sum = op(sum,a[i]);
        }
        return sum;
    }

    void update(vector<int> &a, int id , int new_value){
        int val = new_value - a[id];
        b[id/len] = op(b[id/len],val);
        a[id] = new_value;
        return;
    }

};

int32_t main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    sqrt_decomposition sd(a);
    sd.update(a,2,7);
    cout<<sd.query(a,1,3)<<endl;

    return 0;
}