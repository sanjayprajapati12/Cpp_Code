#include<bits/stdc++.h>
using namespace std;

int32_t main(){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0 ;i<n ;i++){
            cin>>a[i];
        }
        vector<int> lis;
        vector<int> information(n,0);
        for(int i=0 ; i<n ; i++){
            if(lis.empty() || lis.back()<a[i]){
                lis.push_back(a[i]);
                information[i] = lis.size();
            }
            else{
                auto it = lower_bound(lis.begin(),lis.end(),a[i]);
                int d = distance(lis.begin(),it);
                lis[d] = a[i];
                information[i] = d+1;
            }
        }
        cout<<lis.size()<<endl;
        int curlen = lis.size();
        vector<int> ans;
        for(int i=n-1 ; i>=0 ; i--){
            if(information[i]==curlen){
                ans.push_back(a[i]);
                curlen--;
            }
        }
        reverse(ans.begin(),ans.end());
        for(auto &x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
    return 0;
}

// 10
// 1 2 9 5 7 12 10 1 11 1