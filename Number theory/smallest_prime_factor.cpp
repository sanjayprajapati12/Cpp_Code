#include <bits/stdc++.h>
using namespace std;
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

    // for test 
    for(int i = 1 ; i<=30 ; i++){
        cout<<i<<" "<<spf[i]<<endl;
    }
}
 
int main()
{
   for(int i = 0 ; i<=N ;i++){
       spf[i]= i;
   }
   Sieve();
   return 0;
}