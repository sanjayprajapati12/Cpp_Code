#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5+5;
vector<int> spf(N,-1);

void Sieve(){
    for (int p = 2; p * p <= N; p++){
        if(spf[p]==p){
            for (int i = p*p; i <= N; i += p){
                if(spf[i]==i)spf[i] = p;
            }
        }
    }   
}

vector<int> all_factor(int n){
    vector<int> ans;
    while(n!=1){
        ans.push_back(spf[n]);
        n = n/spf[n];
    }
    return ans;
}

// when n is too big (ex. 1e12 )
vector<int> factorization(int n){
  vector<int> first_primes;

  if (n == 1)
    return first_primes;

  for(int d = 1, i = 2; i * i <= n ; i += d, d = 2) {
      while (n % i == 0)
        first_primes.push_back(i), n /= i;
  }

  if (n > 1)
    first_primes.push_back(n);

  return first_primes;
}

int32_t main()
{
    vector<int> factor = factorization(1e12);
    for(auto &x:factor){
        cout<<x<<" ";
    }
    cout<<endl;


    // using sieve 
    for(int i = 0 ; i<=N ;i++){
       spf[i]= i;
    }
    Sieve();
    vector<int> ans = all_factor(100000);
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}