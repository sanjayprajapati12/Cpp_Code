#include<iostream>
using namespace std;

bool ispowerOF2(int  n){
    if(n==1) return  false;
    return (n && !(n & (n-1)));
}

bool ispowerOF4(int n) {
    if(n==1) return  false;
    return !(n&(n-1)) && (n&0x55555555);
    //check the 1-bit location;
    // 0x55555555 is the no with all odd bit set 1 and even set 0
    // 0xAAAAAAAA is the no with all odd bit set 0 and even set 1
}

int main(){
     cout<<ispowerOF2(1)<<endl;
     cout<<ispowerOF4(1)<<endl;
     return 0;
}