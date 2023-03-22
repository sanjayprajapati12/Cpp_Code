#include<bits/stdc++.h>
using namespace std;

int first(vector<int> &a,int n){
    int l=0,r=a.size()-1;
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2 ; 

        if(a[mid]>n){
            r = mid - 1;
        }
        else if(a[mid]<n){
            l = mid + 1;
        }
        else{
            ans = mid ;
            r = mid-1;
        }
    }
    return ans;
}

int last(vector<int> &a,int n){
    int l=0,r=a.size()-1;
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2 ; 

        if(a[mid]>n){
            r = mid - 1;
        }
        else if(a[mid]<n){
            l = mid + 1;
        }
        else{
            ans = mid ;
            l = mid + 1;
        }
    }
    return ans;
}

int32_t main(){
    
    vector<int> v = {1, 3, 5, 5, 5, 5, 67, 123, 125} ;
    cout<<first(v,5)<<endl;
    cout<<last(v,5)<<endl;
    
    return 0;
}