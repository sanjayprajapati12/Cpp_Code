#include<bits/stdc++.h>
using namespace std;

int peak_element(vector<int> &a){
    int l=0,r=a.size()-1;
    int peak = 0;
    while(l<=r){
        int mid = l + (r-l)/2 ; 

        // for updating peak
        if(a[mid]>a[mid+1]){
            peak=a[mid];
        }
        else if(a[mid-1]>a[mid]){
            peak= a[mid-1];
        }

        // for shifting l and r 
        if(a[l]>=a[mid]){
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }

    return peak;
}

int32_t main(){
    
    vector<int> v = {9,10,1,2,3,5,8} ;
    cout<<peak_element(v);
    
    return 0;
}