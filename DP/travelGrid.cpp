#include<bits/stdc++.h>
#define ll long long
using namespace std;

int grid(int n,int m){
    if(n==0 || m==0 ) return 0;
    if(n==1 && m==1) return 1;

    return grid(n-1,m) + grid(n,m-1);
}
int main(){
    cout<<grid(2,3);
    return 0;
}