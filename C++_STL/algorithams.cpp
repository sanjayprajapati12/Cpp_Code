#include<bits/stdc++.h>
#define ll long long
using namespace std;
    
int main(){
    // lamda function
    cout<< [](int x){return x+2;}(2) <<endl;

    auto sum = [](int x,int y ){return x+y;};
    cout<< sum(2,4)<<endl;

    vector<int> v = {2,5,6};
    cout<< all_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;

    cout<< any_of(v.begin(),v.end(),[](int x){return x<0;})<<endl;
    
    cout<< none_of(v.begin(),v.end(),[](int x){return x<0;})<<endl;

    // priority_queue = max heap 

    return 0;
}