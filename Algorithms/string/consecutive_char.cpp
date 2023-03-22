#include<bits/stdc++.h>
using namespace std;
// Find the max length of substring which have same char

#define int long long int
#define endl '\n'

int32_t main(){
    string s;cin>>s;
    int ans = INT_MIN;
    for(int i=0 , j=0 ;i<s.length();i=j){
        while(s[i]==s[j])j++;
        ans = max(ans,j-i);
    }
    cout<<ans<<endl;
    return 0;
}