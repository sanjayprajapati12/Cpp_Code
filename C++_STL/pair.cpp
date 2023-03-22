#include<bits/stdc++.h>
using namespace std;
    
int main(){
    
    pair<int,string> p;
    // pair<int,string> &p1 = p; copy karke use bhi kar sakte hai 
    p  = { 0 , "sanjay"};
    cout<<p.first <<" "<<p.second<<endl;

    //vector of pair is beneficial to declared 
    pair<int,int> p_array[2];
    p_array[0] = {1,2};
    p_array[1] = {5,6};
    for(int i=0 ;i<2 ;i++){
        cout<<p_array[i].first <<" "<<p_array[i].second<<endl;
    }
    return 0;
}