#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct manacher{
    vector<int> p;
    manacher(string temp){
        string s = "#";
        for(auto &x:temp){
            s += x;
            s += "#";
        }
        run_it(s);
    }

    void run_it(string s){
        int n = s.length();
        p.assign(n,1LL);
        int l = 1 ;
        int r = 1 ; 
        for(int i=1 ; i<n ; i++){
            p[i] = max(0LL,min(r-i,p[l+r-i]));
            while(i-p[i]>=0 && i+p[i]<n && s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }
            if(p[i]+i>r){
                r = p[i] + i;
                l = i - p[i];
            }
        }
    }

    int getLongest(int cen , int odd){
        int pos = 2*cen + 1 + (!odd);
        return p[pos]-1;
    }

    bool is_pal(int l,int r){
        int len = (r-l+1);
        if(len<=getLongest((l+r)/2,l%2==r%2)){
            return true;
        }
        else{
            return false;
        }
    }
};

int32_t main(){
    string s;cin>>s;
    manacher m(s);
    
    return 0;
}