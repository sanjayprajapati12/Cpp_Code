#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define INF 1e12



int MCM(string str, int i , int j , bool istrue){
    if(i>j) return 0;

    if(i==j){
        if(istrue==true) return (str[i]=='T');
        else return (str[i]=='F');
    }
    int ans = 0 ;
    for(int k = i+1  ; k<=(j-1) ; k+=2){
        int lt = MCM(str,i,k-1,true);
        int lf = MCM(str,i,k-1,false);
        int rt = MCM(str,k+1,j,true);
        int rf = MCM(str,k+1,j,false);
        
        if(str[k]=='&'){
            if(istrue==true)
                ans +=(lt*rt);
            else{
                ans+= (lt*rf) + (lf*rt) + (lf*rf);
            }
        }
        else if(str[k]=='|'){
            if(istrue==true){
                ans+= (lt*rf) + (lf*rt) + (lt*rt);
            }
            else{
                ans+=(lf*rf);
            }
        }
        else{
            if(istrue==true){
                ans+= (lf*rt) + (lt*rf);
            }
            else{
                ans+= (lt*rt) + (lf*rt);
            }
        }
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
    cout<<MCM(str,i,j,true)<<endl;

    return 0;
}