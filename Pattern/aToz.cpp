#include<iostream>
using namespace std;

int main()   
{
    
    for(int i=1 ; i<=26 ; i++){
        char a='z';
        for(int j=1 ; j<=26-i ; j++){
            cout<<"--";
        }
        for(int k=1 ; k<=i ; k++){
            cout<<a<<"-";
            a--;
        }
        for(int l=1 ; l<=i-1; l++){
            cout<<a<<"-";
            a++;
        }
        for(int j=1 ; j<=26-i ; j++){
            cout<<"--";
        }
        cout<<"\n";
     }
     for(int i=25 ; i>=1 ; i--){
         char a='z';
        for(int j=1 ; j<=26-i ; j++){
            cout<<"--";
        }
        for(int k=1 ; k<=i ; k++){
            cout<<a<<"-";
            a--;
        }
        for(int l=1 ; l<=i-1; l++){
            cout<<a<<"-";
            a++;
        }
        for(int j=1 ; j<=26-i ; j++){
            cout<<"--";
        }
        cout<<"\n";
     }
    return 0;
}
