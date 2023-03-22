#include<bits/stdc++.h>
using namespace std;

#define fo(i,x,n) for(int i=x; i<=n;i++) 
#define rfo(i,x,n) for(int i=x; i>=n;i--) 

void heapify(vector<int> &a , int n, int i ){
    int maxId = i ;
    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && a[l] > a[maxId])
       maxId = l;
  
    if (r < n && a[r] > a[maxId])
       maxId = r;
  
    if (maxId != i) {
      swap(a[i], a[maxId]);
      heapify(a, n, maxId);
    }

}
void heapsort(vector<int> &a){
    int n = a.size();

    rfo(i,n/2-1,0){
        heapify(a,n,i);
    }

    rfo(i,n-1,1){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int32_t main(){
    int n;
    cin>>n;
    vector<int> v(n);

    fo(i,0,n-1) cin>>v[i];

    heapsort(v);

    fo(i,0,n-1){
        cout<<v[i]<<" ";
    }
    return 0;
}
