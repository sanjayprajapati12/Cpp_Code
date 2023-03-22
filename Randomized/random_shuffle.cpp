#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}

int get_rand(int a,int b){
    srand(time(NULL));
    return (a + rand()%(b-a+1));
}

int32_t main(){
    
    vector<int> a = {1,4,2,5,7,8};
    int n = a.size();
    for(int i=0 ; i<n ; i++){
        int j = get_rand(0,i);
        swap(a[i],a[j]);
    }
    for(auto &x:a){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}