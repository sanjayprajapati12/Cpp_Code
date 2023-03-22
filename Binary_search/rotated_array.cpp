#include<bits/stdc++.h>
using namespace std;

int first_element(vector<int> &a){
    int l=0,r=a.size()-1;
    int first_index = 0;
    while(l<=r){
        int mid = l + (r-l)/2 ; 
        if(a[mid]>a[mid+1]){
            first_index=mid;
        }
        else if(a[mid-1]>a[mid]){
            first_index=mid-1;
        }

        if(a[l]>=a[mid]){
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }

    return first_index+1;
}

int32_t main(){
    
    vector<int> v = {9,10,1,2,3,5,8} ;
    cout<<first_element(v);
    
    return 0;
}