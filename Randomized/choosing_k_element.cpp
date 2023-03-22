#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
     return (b==0) ?  a : gcd(b,a%b);
}
// given n numbers . choose k random number with equal probability

int get_rand(int a,int b){
    srand(time(NULL));
    return (a + rand()%(b-a+1));
}

int32_t main(){
    
    vector<int> a = {1,4,2,5,7,8};
    int n = a.size();
    int k = 3;
    vector<int> reservoir(k);
    for(int i=0 ; i<n ; i++){
        if(i<k){
            reservoir[i] = a[i];
        }
        else{
            int j = get_rand(0,i);
            // cout<<i<<" "<<j<<endl;
            swap(a[i],a[j]);
            if(j<k){
                reservoir[j] = a[i];
            }
        }
    }
    for(auto &x:reservoir){
        cout<<x<<" ";
    }

    return 0;
}