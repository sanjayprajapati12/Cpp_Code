#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;

const int N = 1e5 + 5;
vector<int> pi(N,0);
vector<int> kmp(string &s){
    int n = s.length();
    vector<int> pi(n);  
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]){
            // this is not a big step . this step is same as we do j = pi[i-1] . Think !
            j = pi[j-1];
        }
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int32_t main(){

    // testing
    string s;cin>>s;
    vector<int> pi = kmp(s);

    int n = pi.size();
    for(int i=0 ;i<n;i++){
        cout<<pi[i]<<" ";
    }
    cout<<endl;


    // pattern searching;
    
    // string main_string,pattern;
    // cin>>main_string>>pattern;
    // string  temp = pattern+"#"+main_string;
    // vector<int> lps = kmp(temp);
    // vector<int> matched_index;
    // for(int i=0 ; i<lps.size(); i++){
    //     if(lps[i]==pattern.size()){
    //         // think about this 
    //         matched_index.push_back(i-2*pattern.size());
    //     }
    // }
    // for(auto &x:matched_index){
    //     cout<<x<<" ";
    // }
    // cout<<endl;


    // Counting the number of occurrences of each prefix
    // string s;cin>>s;
    // vector<int> pi = kmp(s);

    // vector<int> ans(n + 1);
    // // ans[i] -> how_many i length prefix are there
    // for (int i = 0; i < n; i++){
    //     ans[pi[i]]++;
    // }

    // for (int i = n-1; i > 0; i--){
    //     ans[pi[i-1]] += ans[i];
    // }

    // for (int i = 0; i <= n; i++){
    //     ans[i]++;
    // }

    // Given a string s of length n. 
    // We want to find the shortest "compressed" representation of the string,
    //  i.e. we want to find a string  t of smallest length such that  
    // s can be represented as a concatenation of one or more copies of t.  
    string s;cin>>s;
    vector<int> pi = kmp(s);
    int n = s.length();
    assert(n==pi.length());
    int ans = n-pi[n-1];
    if(ans%n){
        ans = n;
    }
    cout<<ans<<endl;
    
    return 0;
}