#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> v , int n , int k){

    int s=0;
    int cnt = 1 ; 
    for(int i=0 ;i<v.size()  ; i++){
        if(v[i]>n)return false;
        if(s+v[i]<=n){
            s+=v[i];
        }
        else{
            cnt++;
            s=v[i];
        }
    }

    if(cnt>k){
        return false;
    }
    else return true;
}

int page_allocation(vector<int> v , int k ){
   int low = INT_MAX;
   int high = 0 ; 
    for(int i=0 ; i<v.size() ; i++){
        low = min(low,v[i]);
        high += v[i] ;
    }

    while(low<=high){
        int mid = low + (high-low)/2;
        if(check(v,mid,k)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low; 
}

int32_t main(){
    
    vector<int> v = {12,34,67,90};
    int k = 2 ; 
    cout<<page_allocation(v,k);
    
    return 0;
}