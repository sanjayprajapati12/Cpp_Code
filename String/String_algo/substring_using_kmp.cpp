#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 9;
// pattern matching 
// given two string and return position where pattern match

const int N = 1e5 + 5;
vector<int> pi(N,0);
vector<int> kmp(string &s){{
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

}

int32_t main(){
    string text;cin>>text;
    string pattern; cin>>pattern;
    string separator = "#//";
    string s = pattern + separator + text;
    vector<int> pi = kmp(s);

    int m = pattern.length();
    int n = pi.size();
    int l = separator.length();

    for(int i=m+l;i<n;i++){
        if(pi[i]==m){
            cout<<i-m-l<<" ";
        }
    }

    return 0;
}