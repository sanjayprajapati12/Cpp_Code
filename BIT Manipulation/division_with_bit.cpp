#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int a,int b){
    if(b<0){
        while(b){
        a>>1;
        b>>1;
        }
        a-=2*a;
    }
    else{
        while(b){
            a>>1;
            b>>1;
        }
    }    
    return a;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<"a/b = "<<solve(a,b);
    return 0;
}