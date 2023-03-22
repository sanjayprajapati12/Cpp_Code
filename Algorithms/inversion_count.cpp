#include<bits/stdc++.h>
using namespace std;


int merge(vector<int> &a ,vector<int> &temp , int left , int mid , int right){

    int i = left ;
    int j = mid ;
    int k = left;
    int ans = 0 ;
    while(i<(mid) && j<=right){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
            ans += (mid-i);
        }
    }

    while(i<mid){
        temp[k++] = a[i++];
    }
    while (j<=right){
        temp[k++] = a[j++];
    }

    for(int i=left ; i<=right ; i++){
        a[i] = temp[i];
    }
    return ans;
}

int mergesort(vector<int> &a ,vector<int> &temp , int left , int right){
    int ans = 0 ;
    if(left < right){
        int mid = (right + left)/2;

        ans += mergesort(a,temp,left,mid);
        ans += mergesort(a,temp,mid+1,right);

        ans += merge(a,temp,left,mid+1,right);
    }
    return ans;
}

struct BITpr{
    vector<int> bit;
    int n;

    BITpr(vector<int> &a){
        // n = a.size();
        n = *max_element(a.begin(),a.end());
        bit.resize(n+1,0ll);
    }
    void add(int i,int x){
        for(++i;i <= n;i += (i & (-i))) bit[i] += x;
    }

    // prefix sum of i;
    int sum(int i){
        int res = 0;
        for(++i;i > 0;i -= (i & (-i))) res += bit[i];
        return res;
    }
 
    int getSum(int l,int r){
        return (sum(r) - sum(l));
    }
};
 
int main(){
    vector<int> v = {5,3,2,4,1};
    int inv_cnt =  0 ;

    // O(n^2)
    for(int i = 0 ; i<v.size() ; i++){
        for(int j=i+1 ; j<v.size() ; j++){
            if(v[j]<v[i]){
                inv_cnt++;
            }
        }
    }
    cout<<inv_cnt<<endl;

    // using merge-sort tc -> O(nlog(n))
    int n = v.size();
    vector<int> temp(n);
    int ans = mergesort(v,temp,0,n-1);
    
    cout<<ans<<endl;

    // using BIT(fenwick tree) tc -> O(nlog(n))
    vector<int> a = {5,3,2,4,1};
    BITpr b(a);
    int res = 0;
    int mx = *max_element(a.begin(),a.end());
    for(int i=0 ; i<a.size() ;i++){
        res += b.getSum(a[i]-1,mx-1);
        b.add(a[i]-1,1);
    }
    cout<<res<<endl;
    return 0;
}