#include<bits/stdc++.h>
using namespace std;

// sort the array and check two consecutive no
int minimum_xor(int a[],int n){
    sort(a,a+n);
    int ans=INT_MAX;
    for(int i=0 ;i<n-1 ;i++){
        ans = min(ans,a[i]^a[i+1]);
    }
    return ans;
}

// [3,10,5,25,2,8]
// left
int maximum_xor(int a[],int n) {
    int mask=0,ans=0;
    for(int i=31;i>=0;i--){
        mask = mask | (1<<i);
        unordered_set<int> s;
        for(int i=0 ;i<n;i++)
            s.insert(a[i]&mask);
                    
        int temp=ans|(1<<i);
        for(int prefix:s){
            if(s.find(prefix^temp)!=s.end()){
                ans=temp;
                break;
            }
        }
    }
    return ans;
}


// no. of pairs with given sum
int given_sum_pair(int a[],int n,int sum){

    map<int,int> m;
    for (int i = 0; i < n; i++){
        m[a[i]]++;
    }

    int ans =0;
    for (int i = 0; i < n; i++){
        ans += m[sum - a[i]];
        if (sum - a[i] == a[i])
            ans--;
    }
    
    return ans/2;    
}

int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ;i<n;i++){
        cin>>a[i];
    }
    
    cout<<minimum_xor(a,n)<<endl;
    cout<<maximum_xor(a,n)<<endl;
    cout<<given_sum_pair(a,n,5)<<endl;

    return 0;
}