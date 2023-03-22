// given string of length n , find lexiographically smallest string with size k 
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    string s;cin>>s;
    int k; cin>>k;
    int n = s.length();
    stack<char> st;
    
    for(int i=0 ; i<n ; i++){
        while((!st.empty()) && (s[i]<st.top()) && (st.size()+n-i-1)>=k){
            st.pop();
        }

        if(st.empty() || st.size()<k){
            st.push(s[i]);
        }
    }
    
    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}

// tc : 
// bbcaab
// 3