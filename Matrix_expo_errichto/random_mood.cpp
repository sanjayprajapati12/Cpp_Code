// if we can do dp in constant space then the we think about matrix expo
#include<bits/stdc++.h>
using namespace std;

#define fo(i,x,n) for(int i=x; i<=n;i++) 

struct Matrix{
    // in small size array is better otherwise use vector
    double a[2][2] = {{0,0},{0,0}};
    Matrix operator *(const Matrix &other){
        Matrix product;
        fo(i,0,1){
            fo(j,0,1){
                fo(k,0,1){
                    product.a[i][k] += a[i][j] *other.a[j][k];
                }
            }
        }
        return product;
    }
};

Matrix matrix_expo(Matrix a , int b){
    Matrix ans;
    // identity matrix;
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
        double p;
        cin>>n>>p;
        Matrix single;
        // 0 means happy , 1 means sad
        single.a[0][0] = 1-p;
        single.a[0][1] = p;
        single.a[1][0] = p;
        single.a[1][1] = 1-p;
        Matrix ans = matrix_expo(single,n);  
        cout<<setprecision(10) << fixed << ans.a[0][0]<<endl;
    }
    return 0;
}