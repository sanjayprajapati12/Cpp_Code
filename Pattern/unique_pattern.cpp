#include<iostream>
using namespace std;

int main(){
    
   for(int i=1 ; i<=10 ; i++){
        for(int j=1 ; j<=(10-i) ; j++){
            cout<<"  ";
        }
        for(int k=1 ; k<=(2*i-1) ; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=4 ; i>=1 ; i--){
        for(int j=1 ; j<=(5-i) ; j++){
            cout<<"  ";
        }
        for(int k=1 ; k<=(2*i-1) ; k++){
            cout<<"* ";
        }
        for(int j=1 ; j<=(5-i) ; j++){
            cout<<"  ";
        }
        for(int k=1 ; k<=1 ; k++)
            cout<<"* ";
        for(int j=1 ; j<=(5-i) ; j++){
            cout<<"  ";
        }
        
        for(int k=1 ; k<=(2*i-1) ; k++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=0 ; i<6 ; i++){
        for(int j=0 ; j<38 ; j++){
            if(j==18){
                cout<<"* ";
            }
            else{
                cout<<" ";
            }
        }
        cout<<"\n";
    }

    
    return 0;
}