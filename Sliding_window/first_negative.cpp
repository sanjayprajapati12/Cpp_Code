#include<bits/stdc++.h>
using namespace std;


#define int long long int

int32_t main(){
    int n,k;
    cin>>n>>k;
    int arr[n];

    for(int i=0 ;i<n;i++) cin>>arr[i];

    int firstNegativeIndex = 0;
    int firstNegativeElement;
    
    for(int i = k - 1; i < n; i++){
        // skip out of window and positive elements
        while((firstNegativeIndex < i ) && (firstNegativeIndex <= i - k || arr[firstNegativeIndex] > 0))
            firstNegativeIndex ++;
        
        // check if a negative element is found, otherwise use 0
        if(arr[firstNegativeIndex] < 0){
            firstNegativeElement = arr[firstNegativeIndex];
        }
        else{
            firstNegativeElement = 0;
        }

        cout<<firstNegativeElement << " ";
    }

    return 0;
}