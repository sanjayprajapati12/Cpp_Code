#include<bits/stdc++.h>
using namespace std;


#define int long long int

int32_t main(){
    int n,k;
    cin>>n>>k;
    int a[n];

    for(int i=0 ;i<n;i++) cin>>a[i];

    int maxi = INT_MIN;
    for(int i=0 ;i<k;i++)  {
        maxi = max(maxi,a[i]);
        if(i==k-1)  cout<<maxi<<" ";
    }

    for(int i=k ; i<n ; i++){
        // we can optimized this with STL --> you can figure out this
        if(maxi==a[i-k]){
            int temp=INT_MIN;
            for(int j=i-k+1 ; j<=i;j++){
                temp = max(temp,a[j]);
            }
            maxi=temp;
        }
        else{
            maxi=max(maxi,a[i]);
        }
        cout<<maxi<<" ";
    }
    
    return 0;

}