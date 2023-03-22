#include<bits/stdc++.h>
using namespace std;


#define int long long int

int32_t main(){
    // string only contains 0 and 1
    string s;
    cin>>s;
    int n= s.length();
    int sum=0;
    int ans = INT_MIN;

    // we treat 0 as 1 and 1 as -1 
    for(int i=0 ;i<s.length();i++){
        int value =0;
        if(s[i]=='0'){
            value=1;
        }
        if(s[i]=='1'){
            value=-1;
        }
        sum=max(sum+value,value);
        ans = max(ans,sum);
    }

    cout<<ans<<endl;
    return 0;
}