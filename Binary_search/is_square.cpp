#include<bits/stdc++.h>
using namespace std;

bool isSquare(int n){
    int l=0,r=n-1;
    while(l<=r){
        int mid = l + (r-l)/2 ; // also write (l+r)/2 , but sometimes it gives overflow . I think you know what i am talking about
        if(n==(mid*mid)){
            return true;
        }
        else if(n>mid*mid){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return false;
}
int32_t main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        if(isSquare(n) || n==1){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}