#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<bool> isPrime(N+1,true);

void Sieve(){  
    isPrime[1] = false;
    // if you want to store all prime then limit is p<=N . keep this in mind 
    for (int p = 2; p*p <= N; p++){
        if (isPrime[p] == true){
            for (int i = 2 * p; i <= N; i += p)
                isPrime[i] = false;
        }
    }
}

int main(){
    Sieve();    
    int ans = 0 ;
    for(int i=1 ; i<=N-1 ; i++){
        if(isPrime[i]){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}