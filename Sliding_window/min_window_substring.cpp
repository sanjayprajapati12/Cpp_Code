#include <bits/stdc++.h>
using namespace std;

#define fo(i,x,y) for(int i=x ; i<=y ; i++)
int main(){

    string s,t;
    cin>>s>>t;

    int n = s.length();
 
    int m[256] = { 0 };

    int ans = INT_MAX; 
    int count = 0;

    for (int i = 0; i < t.length(); i++) {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }

    int i = 0;
    for(int j=0 ; j<n;j++) {
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;

        if (count == 0){
            while (count == 0){
                ans = min(ans, j - i + 1);

                m[s[i]]++;
                if (m[s[i]]>0)
                    count++;

                i++;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
