#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){

    string s;
    cin>>s;
    int n = s.size();
    int best_len = 0;
    string ans = "";

    // this is for string like abcba
    for(int mid = 0 ; mid <n ; mid++){
        for(int x=0 ; mid - x >= 0 && mid + x < n; x++){
              if(s[mid-x]!=s[mid+x]){
                  break;
              }
              int len=2*x+1;
              if(len > best_len){
                  best_len = len;
                  ans = s.substr(mid-x , len);
              }
        }
    }

    // this is for string like abba
    for(int mid = 0 ; mid < n-1 ; mid++ ){
        for(int x = 1 ; mid - x + 1>= 0 && mid+x < n ; x++){
            if(s[mid-x+1]!=s[mid+x]){
                break;
            }
            int len= 2*x;
            if(len > best_len){
                best_len = len;
                ans = s.substr(mid-x , len);
            }
        }
    }

    cout<<best_len<<endl;
    cout<<ans<<endl;

    // bottom-up dp
    // dp[i][j] --> substr(i,j) is pallindrom or not
    vector<vector<bool>> dp(n,vector<bool> (n,false));
    int lps = 1;
    int no_of_ps = 0;

    for(int g=0 ; g<n ; g++){
        for(int i=0 , j=g ; j<n ; i++,j++){
            if(g==0){
                dp[i][j]=true;
            }
            else if(g==1){
                dp[i][j]  = (s[i]==s[j]) ;
            }
            else{
                if((s[i]==s[j]) && dp[i+1][j-1]==true){
                    dp[i][j]=true;
                }
            }

            if(dp[i][j]){
                no_of_ps++;
                lps = max(lps,g+1);
            }
        }
    }
   
    cout<<"No. of pallindromic substring : "<<no_of_ps<<endl;
    cout<<lps<<endl;

    return 0;
}