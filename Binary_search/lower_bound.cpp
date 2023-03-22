#include<bits/stdc++.h>
using namespace std;

// first element which is >= x is called lower_bound(x)
int lower_bound(int n,vector<int> &a){
    int l=0,r=a.size()-1;
    int ans=-1;
    while(l<=r){
        int mid = l + (r-l)/2 ; 
        if(a[mid]==n){
            ans=mid;
            return ans;
        }
        else if(a[mid]>n){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

int lower(vector<int> &a,int x){
    int l = 0;
    int r = a.size();
    while(r-l>1){
        int mid = (l+r)/2;
        if(a[mid]<x){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}

int32_t main(){
    
    vector<int> v = {1,2,3,5,8,9,10};
    assert(lower(v,6)==lower_bound(6,v));
    assert(lower(v,8)==lower_bound(8,v));
    assert(lower(v,4)==lower_bound(4,v));
    cout<<lower_bound(6,v)<<endl;
    cout<<lower_bound(8,v)<<endl;
    cout<<lower_bound(4,v)<<endl;
    
    return 0;
}