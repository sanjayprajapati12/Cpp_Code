#include<bits/stdc++.h>
using namespace std;

int32_t main(){

    string str;
    cin>>str;
    int k;
    cin>>k;
    int n = str.length();
    unordered_set<char> s;
    map<char,int> m;
    
    int ans = INT_MIN ;
    for (int i = 0, j = 0; j < n; j++){
        s.insert(str[j]);
        m[str[j]]++;
 
        while(s.size()>k){
            m[str[i]]--;
            if (m[str[i]] == 0){
                s.erase(str[i]);
            }
            i++;
        }

        ans = max(ans,j-i+1);
    }

    cout<<ans<<endl;

    return 0;
}