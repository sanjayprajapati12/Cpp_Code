#include<bits/stdc++.h>
using namespace std;

#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define int long long
const int mod = 1e9 + 7;
struct Matrix{
    int a[2][2] = {{0,0},{0,0}};
    Matrix operator *(const Matrix &other){
        Matrix product;
        fo(i,0,1){
            fo(j,0,1){
                fo(k,0,1){
                    product.a[i][k] += (a[i][j] *other.a[j][k]);
                    product.a[i][k] %= mod;
                }
            }
        }
        return product;
    }
};

Matrix matrix_expo(Matrix a , int b){
    Matrix ans;
    fo(i,0,1){
        ans.a[i][i] = 1;
    }
    while(b>0){
        if(b&1){
            ans = ans * a;
        }
        a = a*a;
        b /=2;
    }
    return ans;
}

int32_t main(){
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        Matrix single;
        int flip = 5 , happy = 1 , sad = 2 , nothing = 18;
        single.a[0][0] = happy + nothing;
        single.a[0][1] = flip + sad;
        single.a[1][0] = flip + happy;
        single.a[1][1] = sad + nothing;
        Matrix ans = matrix_expo(single,n);  
        cout<<ans.a[0][0]<<endl;
    }
    return 0;
}