#include<iostream>
using namespace std;

// Best	O(n*log n)
// Worst	O(n2)
// Average	O(n*log n)

int partition(int arr[],int l , int r ){
    int pivot = arr[r];

    int i = l ;

    for(int j = l ; j< r; j++){
        if(arr[j] <= pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }

    swap(arr[i],arr[r]);

    return i;
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int p = partition(arr,l,r);
     
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }   
}

int main(){

    int n; 
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    quickSort(array,0,n-1);
    
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }

    return 0;
}