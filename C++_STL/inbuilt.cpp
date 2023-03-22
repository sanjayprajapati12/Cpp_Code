#include<bits/stdc++.h>
#define ll long long
using namespace std;
    
int main(){
    vector<int> v = {2,3,1,6,7,6};
    int min = *min_element(v.begin(),v.end());
    cout<<min<<endl;

    int sum = accumulate(v.begin(),v.end(),0);
    cout<<sum<<endl;

    int ct = count(v.begin(),v.end(),6);
    cout<<ct<<endl;

    int element = *find(v.begin(),v.end(),7);
    cout<<element<<endl;
    
    reverse(v.begin(),v.end());
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    
    string s = "asldsveiru";
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}