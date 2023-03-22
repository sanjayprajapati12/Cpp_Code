#include<bits/stdc++.h>
using namespace std;
// pattern matching 
// given two string and return position where pattern match
#define int long long int 
const int mod = 1e9 + 9;

int32_t main(){
    string s,pattern;
    cin>>s>>pattern;
    int n = s.length();
    int m = pattern.length();
    const int p = 31;
    int pow = 1 ;

    // generate value for pattern
    int value = 0;
    for(int i=0 ;i<m ;i++){
        value = value + ((pattern[i] - 'a' + 1)*pow)%mod;
        pow = (pow*p)%mod;
    }

    // rabin karp
    vector<int> hash(n,0);
    vector<int> preffix(n,0);
    pow = p ; 
    hash[0] = s[0] - 'a' + 1;
    preffix[0] = 1;
    for(int i=1 ; i< n; i++){
        hash[i] = hash[i-1] + ((s[i]-'a'+1)*pow) %mod ; 
        preffix[i] = pow;
        pow = (pow*p)%mod;
    }
    
 
    vector<int> ans;
    for(int start=0 , end=m-1 ; end<n ; start++,end++){
        int current = hash[end] ;
        if(start>0) current = ( current - hash[start-1] + mod ) % mod;
        
        if((current)%mod == (value*preffix[start])%mod){
            ans.push_back(start+1);
        }
    }

    if(ans.size()==0)cout<<"Not found"<<endl;
    else{
        cout<<ans.size()<<endl;
        for(auto x:ans){
            cout<<x<<" ";
        }
    }

    return 0;
}