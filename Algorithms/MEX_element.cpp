#include<bits/stdc++.h>
using namespace std;

// tc -> O(n) and space -> O(1)
int MEX(vector<int> &a){
    int n = a.size();
    for(int i=0 ; i<n ;i++){
        while(a[i]>=0 && a[i]<n && a[i]!=a[a[i]]){
            swap(a[i],a[a[i]]);
        }
    }

    for(int i=0 ; i<n ; i++){
        if(a[i]!=(i)){
            return i;
        }
    }
    return n;
}

int32_t main(){
    // tc -> O(n) and space -> O(n) store count and return the first element with count zero.
    vector<int> v = {3,0,2,4};
    cout<<MEX(v)<<endl;
    return 0;
}