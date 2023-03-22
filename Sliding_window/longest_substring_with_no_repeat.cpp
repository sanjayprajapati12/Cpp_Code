#include<bits/stdc++.h>
using namespace std;

int32_t main(){

    string str;
    cin>>str;
    int n = str.length();
    map<char,int> m;
    
    int ans = INT_MIN ;
    for (int i = 0, j = 0; j < n; j++){
        m[str[j]]++;
        while(m[str[j]]==2){
            m[str[i]]--;
            i++;
        }
        ans = max(ans,j-i+1);
    }

    cout<<ans<<endl;

    return 0;
}