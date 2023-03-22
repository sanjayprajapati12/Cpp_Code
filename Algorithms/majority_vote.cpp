// Boyer-Moore majority vote algorithm
#include<bits/stdc++.h>
using namespace std;

// only aply when majority element are there 
// majority element is the element which occur >=n/2 times in array

int32_t main(){

    vector<int> v = {6,7,8,6,6,11,6,3,6,6,5};
    int n = v.size();
    int m = -1;
    int c=0;
    for(int i=0 ;i<n;i++) {
        cout<<c<<" ";
        if(c==0){
            m = v[i];
            c=1;
        }
        else{
            if(m==v[i]){
                c++;
            }
            else{
                c--;
            }
        }
    }
    cout<<endl;
    cout<<m<<endl;
    return 0;
}