#include<bits/stdc++.h>
using namespace std;


int main(){
    // pointer
    int x=4;
    int *ptr;
    ptr = &x;
    *ptr = 5;
    cout<<ptr<<" "<<*ptr<<endl;

    // arrat pointer
    int a[10];
    cout<<"array pointer - "<<a<<endl;
    
    // double pointer
    int y = 10;
    int *p;
    int **pp;
    p = &y;
    pp = &p ;
    cout<<"double pointer"<<endl;
    cout<<p<<" "<<*p<<endl;
    cout<<pp<<" "<<*pp<<" "<<**pp<<endl;
    return 0;
}