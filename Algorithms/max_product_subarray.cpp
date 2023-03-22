#include<iostream>
#include<climits>

using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    // we can prove that ans subarray is either starting from a[0] or ending with a[n-1] --> if 0 is not presenst
    // if 0 is present than starting is next index of 0

    int ans = INT_MIN;
    int curr=1;
    // this is for subarray starting with a[0]
    for(int i=0 ;i<n ; i++ ){
        curr*=a[i];
        ans = max(curr,ans);
        if(curr==0){
            curr=1;
        }
    }

    curr=1;
    for(int i=n-1 ; i>=0 ; i-- ){
        curr*=a[i];
        ans = max(curr,ans);
        if(curr==0){
            curr=1;
        }
    }

    cout<<ans<<endl;
return 0;
}