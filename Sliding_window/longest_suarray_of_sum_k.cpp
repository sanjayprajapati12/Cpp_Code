#include<bits/stdc++.h>
using namespace std;


#define int long long int
void solve(int arr[],int n,int k){
    int i=0,j=0,sum=0;
    int ans=0;
    while(j<n)
    {
        sum=sum+arr[j];
        if(sum<k){
            j++;
        }
        else if(sum==k){
            ans=max(ans,j-i+1);
            j++;
        }
        else
        {
            while(sum>k)
            {
                if(arr[i]>0){
                    sum=sum-arr[i];
                    i++;
                }else{
                    break;
                }
            }
            j++;
        }
    }
    
    cout<<ans<<endl;
}

int32_t main(){
    int n,k;
    cin>>n>>k;
    int a[n];

    for(int i=0 ;i<n;i++) cin>>a[i];

    // sliding window
    solve(a,n,k);

    // using map
    unordered_map<int, int> map;
 
    map[0] = -1;
 
    int sum = 0;
    int len = 0;
 
    for (int i = 0; i < n; i++){
        sum += a[i];
 
        if(map.find(sum) == map.end()){
            map[sum] = i;
        }

        if (map.find(sum - k) != map.end() ){
            len = max(len, i - map[sum - k]);
        }
    }
 
    cout<<len<<endl;

    return 0;

}