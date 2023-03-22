#include<iostream>
using namespace std;

// Best	O(n*log n)
// Worst	O(n*log n)
// Average	O(n*log n)

void merge(int arr[],int l,int mid , int r ){

    int n1 = mid-l+1;
    int n2 = r-mid;

    int temp1[n1];
    int temp2[n2];
    for(int i=0 ; i<n1 ;i++){
        temp1[i] = arr[l + i];
    }

    for(int i=0 ; i<n2 ;i++){
        temp2[i] = arr[mid + 1 +i];
    }

    int i=0 , j=0 ;
    int k=l;
    while (i<n1 && j<n2)
    {
        if(temp1[i]<=temp2[j]){
            arr[k] = temp1[i];
            k++;
            i++;
        }
        else{
            arr[k] = temp2[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        arr[k] = temp1[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k] = temp2[j];
        k++;
        j++;
    }   

}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = l + (r - l) / 2;

        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

int main(){

    int n; 
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    mergeSort(array,0,n-1);
      
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }

    return 0;
}