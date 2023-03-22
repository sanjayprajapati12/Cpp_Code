// swap sort
#include<bits/stdc++.h>
using namespace std;

void md(int a[],int n){
    for(int i=0 ;i<n;i++) {
        if (a[i]!=(i+1))
            swap(a[i],a[a[i]-1]);
        
        // visulization
        
        // cout<<"i "<<i<<endl;
        // for(int i=0 ; i<n ;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
    }
}

int32_t main(){
    int n = 13;
    int arr[n]= {4,3,2,7,13,2,1,11,12,3,1,9,13};
    md(arr,n);

    vector<int> dupli;
    vector<int> missing;
    for(int i=0 ;i<n;i++) {
        if (arr[i]!=(i+1)){
            dupli.push_back(arr[i]);
            missing.push_back(i+1);
        }
    }
    // for(int i=0 ;i<n;i++) cout<<arr[i]<<" ";
    // cout<<endl;
    // for(auto &x:dupli) cout<<x<<" ";
    // cout<<endl;
    // for(auto &x:missing) cout<<x<<" ";

    return 0;
}