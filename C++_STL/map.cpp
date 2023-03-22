#include<bits/stdc++.h>
#define ll long long
using namespace std;

void print(map<int,string> &m){
    cout<<"size: " <<m.size()<<endl;
    for(auto &value:m){
        cout<<value.first<<" "<<value.second<<endl;
    }
}

int main(){
    
    map<int,string> m;
    m[2] = "gdad"; // insertion = O(log(n))  ,also depends on key below is the exp.
    // m["asgsdg"] = "gdad"; // insertion = s.size() * O(log(n))  
    m[1] = "abss";
    m.insert({4,"gea"});
    // m[2] = "sag";  keys are unique
    auto it = m.find(1); // O(log(n))
    // m.erase(2) ; --> erase element O(log(n))
    // m.clear(); --> clear everything
    if(it == m.end()){
        cout<<"No value";
    }else{
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    print(m);


    unordered_map<int,string> um;
    // insertion --> O(1)
    // erase --> O(1)
    // serching --> O(1)
    // order ma print na thay
    // pair ,set , vector e unordered_map ma compile na thay 
     
     multimap<int,int> m;
    // keys are not unique
     
    return 0;
}