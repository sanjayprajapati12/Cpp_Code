// swap sort
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    vector<int> a = {1,3,4,9};
    vector<int> b = {5,6,9,12,15};

    int i=a.size()-1;
    int j=b.size()-1;

    vector<int> ans(a.size()+b.size());
    int k=0;

    while(i>=0 && j>=0){
        if(a[i]>=b[j]){
            ans[k++] = a[i--];
        }
        else{
            ans[k++] = b[j--];
        }
    }

    while(i>=0){
        ans[k++]=a[i--];
    }

    while(j>=0){
        ans[k++]=a[j--];
    }

    for(auto &x:ans){
        cout<<x<<" ";
    }
    return 0;
}