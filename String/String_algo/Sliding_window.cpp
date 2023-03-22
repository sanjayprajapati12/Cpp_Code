// find a pattern in string 
// t = sanjay's nick-name is sanju
// p = an
// output : 1 , 23
#include<bits/stdc++.h>
using namespace std;

string t,p ;
int lt,lp ;

bool match(int a,int b){
    for(int i=0 ; i<lp ; i++){
        if(t[a+i]!=p[i]) return false;
    }
    return true;
}

int main(){
   
    getline(cin,t);
    getline(cin,p);
    lt = t.length();
    lp = p.length();

    for(int i=0,j=0 ; i<lt ; i++ , j++){
        if(match(i,j)) cout<<i<<" ";
    }
    
    return 0;
}