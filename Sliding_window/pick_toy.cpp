#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n=s.length();

    map<char,int>mp;
    int ans=INT_MIN,i=0,j=0;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()<k){
            j++;
        }
        else if(mp.size()==k){
            ans=max(ans,j-i+1);
            j++;
        }
        else{
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
