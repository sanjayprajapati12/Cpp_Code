#include<bits/stdc++.h>
using namespace std;

int decimal(string s){
    reverse(s.begin(),s.end());
    int cur = 1;
    int ans = 0 ;
    for(auto &c:s){
        int v = c-'0';
        ans += (v*cur);
        cur *= 2;
    }
    return ans;
}

int decimal_front(string s){
    int ans = 0 ;
    for(auto &c:s){
        int v = c-'0';
        ans *= 2;
        ans += v;
    }
    return ans;
}

int32_t main(){
    // 00000000000000000000000100011010
    string s = "00000000000000000000000100011010";
    cout<<decimal(s)<<endl;
    cout<<decimal_front(s)<<endl;
    return 0;
}