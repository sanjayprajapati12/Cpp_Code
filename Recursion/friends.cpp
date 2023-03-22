#include<bits/stdc++.h>
using namespace std;


int recurance(int n){
    if(n==2 || n==1){
        return n;
    }
        return (recurance(n-2))*(n-1) + recurance(n-1) ;    
}
int main(){

    
    cout<<recurance(2)<<endl;
    cout<<recurance(3)<<endl;
    cout<<recurance(4)<<endl;
    cout<<recurance(5)<<endl;
    cout<<recurance(6)<<endl;
    return 0;
}