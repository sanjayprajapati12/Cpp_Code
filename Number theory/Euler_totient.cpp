#include<bits/stdc++.h>
#define int long long
using namespace std;
//  counts the number of integers between 1 and n inclusive, which are coprime to n [represent phi(n)]
//  if p is prime  phi(p) = p - 1
//  if p is prime  phi(p^k) = p^k - p^(k-1)


int phi(int n) {
    // if(n==1) return 1; 
    int result = n;
    for (int i = 2 ; i * i <= n; i++) {
        if (n % i == 0){
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }   
    if (n > 1)
        result -= result / n;
    return result;
}

int32_t main(){

    for(int i=1 ; i<=20;i++){
        cout<<phi(i)<<" ";
    }
    return 0;
}