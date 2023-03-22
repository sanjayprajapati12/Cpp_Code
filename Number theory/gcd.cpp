#include<bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int a,int b){
	if(b==0)
        return a;
    return gcd(b,a%b);
}

// ax + by = gcd(a,b)
// do if b=0 , then gcd(a,b)==a . so x=1,y=0
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main(){
    cout<<gcd(36,25)<<endl;
    
    int x,y;
    cout<<extended_gcd(36,25,x,y)<<endl;
    cout<<x<<" "<<y<<endl;
    return 0;
}