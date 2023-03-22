// Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The task is consider set bits of y in range [l, r] and set these bits in x also. Examples :

// Input  : x = 10, y = 13, l = 2, r = 3
// Output : x = 14

// Binary representation of 10 is 1010 and 
// that of y is 1101. There is one set bit
// in y at 3’rd position (in given range). 
// After we copy this bit to x, x becomes 1110
// which is binary representation of 14.

// Input  : x = 8, y = 7, l = 1, r = 2
// Output : x = 11
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int x,int y,int l,int r){
    for(int j=l ; j<=r ;j++){
        int i=j-1;
        if(((y)&(1<<i)))
            x = ( x | 1<<i);
    }
    return x;
}
int main(){
    int x,y,l,r;
    cin>>x>>y>>l>>r;
    cout<<solve(x,y,l,r);
    return 0;
}