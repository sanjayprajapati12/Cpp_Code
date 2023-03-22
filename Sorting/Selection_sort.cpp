#include<iostream>
using namespace std;

int main(){

    int n; 
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    for(int i=0 ; i<n-1; i++){
        int min_idx = i ;
        for(int j = i+1 ; j<n ;j++){
            if(array[j] < array[min_idx]){
                min_idx = j ;
            }
        }
        swap(array[min_idx],array[i]);
        // for printing steps
        // for(int i=0; i<n; i++){
        //     cout<<array[i]<<" ";
        // }
        // cout<<endl;
    }

    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }

    return 0;
}