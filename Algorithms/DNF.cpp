// Dutch National flag [RRRRRWWWWWBBBBB]
#include<bits/stdc++.h>
using namespace std;

void sort012(int a[],int n){
    int lo=0;
    int mi=0;
    int hi=n-1;
    while(mi<=hi){
        if(a[mi]==0){
            swap(a[lo],a[mi]);
            lo++;
            mi++;
        }
        else if(a[mi]==1){
            mi++;
        }
        else{
            swap(a[hi],a[mi]);
            hi--;
        }
    }
}


void sort0123(int a[],int n){
    int f=0;
    int s=0;
    int t=n-1;
    int c=n-1;
    while(s<=t && s<=c){
        if(a[s]==0){
            swap(a[f],a[s]);
            f++;
            s++;
        }
        else if(a[s]==1){
            s++;
        }
        else if(a[s]==2){
            swap(a[t],a[s]);
            t--;
        }
        else {
            swap(a[c],a[s]);
            c--;
        }
    }
}

int32_t main(){

    int n = 5;
    int arr[n]= {0 , 2 , 1 ,2 , 0 };
    sort012(arr,n);
    for(int i=0 ;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    int m = 12;
    int b[m]= {0 , 2 , 1 , 0 , 1 , 2 , 3 , 2 , 0 , 0 , 1 , 3 };
    sort0123(b,m);
    for(int i=0 ;i<m;i++) cout<<b[i]<<" ";
    return 0;
}