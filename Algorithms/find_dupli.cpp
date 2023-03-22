#include<bits/stdc++.h>
using namespace std;

void find(int arr[],int n){
    for(int i=0 ;i<n;i++) {
        if (arr[abs(arr[i])-1] >= 0)
            arr[abs(arr[i])-1] *= -1;
        else
            cout << abs(arr[i]) << " ";
    }
    cout<<endl;
}
int32_t main(){
    int n = 13;
    int arr[n]= {4,3,2,7,13,2,1,11,12,3,1,9,13};
    find(arr,n);
    cout<<endl;
    return 0;
}