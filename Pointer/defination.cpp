#include<iostream>
using namespace std;

int main()
{
    int a=10;
    int*p = &a;
    cout<<&a<<endl;         //represent adress of a(pointer)
    cout<<p<<endl;       //represent adress of a(pointer)
    cout<<*p<<endl;      //dereference of pointer
    *p++;
    cout<<p<<endl;       //incresed by 4 , because int contain 4 byte;
    int **q= &p;
    cout<<*q;
    cout<<**q;
    
    int arr[]= {12,13,14};
    cout<<*arr<<endl;
    int *ptr = arr;
    for(int i=0 ; i<3 ;i++){
        cout<<*ptr<<endl;
        ptr++;
    }

return 0;
}