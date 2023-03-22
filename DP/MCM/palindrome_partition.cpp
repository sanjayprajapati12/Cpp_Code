#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define INF 1e12

bool isPali(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false ;
        i++;
        j--;
    }
    return true;
}

int MCM(string str, int i , int j ){
    if(i>=j || isPali(str , i , j)) return 0;

    int ans = INF ;
    for(int k = i ; k<=(j-1) ; k++){
        int temp = MCM(str,i,k) + MCM(str,k+1,j) + 1 ;
        ans = min(ans,temp);
    }

    return ans;
}
    
int32_t main(){

    string str;
    cin>>str;
    int n= str.length();

    // recursive
    int i = 0; 
    int j = n-1;  
    cout<<MCM(str,i,j)<<endl;

    // bottom-up DP
    vector<vector<int>> dp(n,vector<int> (n,INF));

    // if you don't want to extra space than you can use the "isPali" function which is already coded.
    vector<vector<bool>> pali(n,vector<bool> (n,INF));
    for (int i = 0; i < n; i++){
            dp[i][i] = 0;
            pali[i][i] = true;
    }

    // L is chain length.
    for (int L = 2 ; L <=n; L++){
        for (int i = 0 , j = L-1 ; j < n ; i++,j++){
            // strore is pallindrom in dp 
            if(L==2) pali[i][j] = (str[i]==str[j]);
            else{
                pali[i][j] = (str[i]==str[j]) && pali[i+1][j-1];
            }

            // if pallindrom then no need to make partition 
            if(pali[i][j]){
                dp[i][j]=0;
            }
            else{
                for (int k = i; k <= j - 1; k++){
                    int temp = dp[i][k] + dp[k + 1][j] + 1 ;
                    dp[i][j] = min(dp[i][j],temp);
                }
            }
        }
    }

    cout<<dp[0][n-1]<<endl;

    return 0;
}