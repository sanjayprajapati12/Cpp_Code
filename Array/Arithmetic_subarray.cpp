#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int array[n];

    for(int i=0 ;i<n ; i++){
        cin>>array[i];
    }
    int ans=2; 
    int pd=array[1]-array[0];
    int i=2;
    int curr=2;

    while(i<n)
    {
        if(pd==array[i]-array[i-1])
        {
            curr++;
        }
        else
        {
            pd=array[i]-array[i-1];
            curr=2;
        }
        ans=max(ans,curr);
        i++;
    }
    cout<<ans;
return 0;
}