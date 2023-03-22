// https://codeforces.com/contest/727/problem/C
#include<bits/stdc++.h>
using namespace std;


#define int long long int
#define endl '\n'
#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define rfo(i,n,x) for(int i=n; i>=x;i--) 

    
int32_t main(){
    
    int n;
    cin>>n;
    vector<int> v(n);
    int f,s,t;
    cout<<"? 1 3"<<endl;
    fflush(stdout);
    cin>>f;
    cout<<"? 2 3"<<endl;
    fflush(stdout);
    cin>>s;
    cout<<"? 1 2"<<endl;
    fflush(stdout);
    cin>>t;
    
    v[0] = (f+t-s)/2;
    v[1] = t - v[0] ; 
    v[2] = f - v[0];
    fo(i,4,n){
        cout<<"? 1 "<<i<<endl;
        fflush(stdout);
        int k ;
        cin>>k;
        v[i-1] = k - v[0];
    }
    cout<<"! ";
    fo(i,0,n-1) cout<<v[i]<<" ";

    return 0;
}
