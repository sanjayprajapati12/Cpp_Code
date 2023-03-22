#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool canSum(int n , int a[]){
    if(n==0) return 0;
    int size = 4 ; // you have to find size of array 
    for(int i=0 ; i<size ;i++){
        if(canSum(n-a[i] ,a))
            return true;
    }
    return false;
}

int main(){
    
    int a[] = {2,3,4,6};
    cout<<canSum(7,a);
    return 0;
}