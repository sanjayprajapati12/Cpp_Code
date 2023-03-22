#include<iostream>
using namespace std;

int main(){
    // 00000000000000000000000100011010 -> means that in set there are 4 elements(count of 1) which are {1,3,4,8}

    // this is how you add elements into set
    int x=0;
    x = x | (1<<1); //add 1
    x = x | (1<<3); //add 3
    x = x | (1<<4); //add 4
    x = x | (1<<8); //add 8
    // this is how you can print elements of set
    for(int i=0 ; i<32; i++){
        if(x&(1<<i)) cout<<i<<" ";
    }
    cout<<endl;

    // thi is how you find no. of elements in set
    cout<<__builtin_popcount(x); // count no of 1's in bit represent of a number

    // set {3,6,8,9}
    int y = (1<<3)|(1<<6)|(1<<8)|(1<<9);

    // union
    int u = x | y ;

    // intersaction
    int i = x & y;
    return 0;
}