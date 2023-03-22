#include<bits/stdc++.h>
using namespace std;

int find_element(vector<int> &a,int target){
    int l=0,r=a.size()-1;
    int first = a[0] ;
    while(l<=r){
        int mid = l + (r-l)/2 ; 
        int value = a[mid];
        if(value==target) return mid;

        bool am_big = ( value >= first );
        bool target_big = ( target >= first );
        if(am_big==target_big){
            if(value<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        else{
            if(am_big){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
    return -1;
}

int32_t main(){
    
    vector<int> v = {9,10,1,2,3,5,8};
    int ans = find_element(v,6);
    (ans==-1) ?  cout<<"Not found" :  cout<<ans ;

    return 0;
}