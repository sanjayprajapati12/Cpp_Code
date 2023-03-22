#include<iostream>
using namespace std;

int main(){
    int r;
    cin>>r;
    int l=r/2;
    int c=(r+3);
    for(int i=1 ; i<=r ; i++){
        for(int j=1 ;j<=c ;j++){
            if((i==1 && j<=l)|| (i==l && j<=l) || j==1  || (j==l && i<=(r/2)) ){
            cout<<"*";
            }
            else{
                cout<<" ";
            }
            
            
            if(j==(l+3) || (i==1 && j>=(l+2)) || (i==r && j>=(l+2)) || j==c ){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}