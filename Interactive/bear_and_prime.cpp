// https://codeforces.com/problemset/problem/679/A
#include<bits/stdc++.h>
using namespace std;

#define int long long int

bool isprime(int n){
    for(int i=2; i*i<=n ;i++){
        if(n%i==0) return false;
    }
    return true;
}

int32_t main(){
    int count=0;
    for(int i=2 ;i<=50 ;i++){
        if(isprime(i)){
            cout<<i<<endl;
            fflush(stdout);
            string s;
            cin>>s;
            if(s.compare("yes")==0){
                count++;
            }

            if(i*i<=50){
                cout<<i*i<<endl;
                fflush(stdout);
                string s;
                cin>>s;
                if(s.compare("yes")==0){
                    count++;
                }
            }
        }
    }
    if(count>=2){
        cout<<"composite"<<endl;
    }
    else cout<<"prime"<<endl;
    
    return 0;
}