// q query
// given l and r . check if it is pallindrom or not
#include<bits/stdc++.h>
using namespace std;
const int m = 1e9 + 9;   

int main(){
    string s;
    cin>>s;
    vector<int> prefix(n,0);
    int p = 31;
    long long int hash_value = 0;
    long long int p_pow = 31;
    prefix[0] = s[0] - 'a' + 1 ; 
    for (int i=1 ; i<s.length()-1 ; i++){
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;

        prefix[i] = ( prefix[i-1] + (s[i]- 'a' + 1) ) % m ; 
    }
    
    cout<<hash_value<<endl;
    return 0;
}