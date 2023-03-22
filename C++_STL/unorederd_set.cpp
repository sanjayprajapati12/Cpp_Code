#include<iostream.h>
#include<unorderd.set>
#define ll long long
using namespace std;
    
int main(){
    
    unorederd_set<int> s;

    s.insert(5);
    s.insert(5);

    s.find(10); // if not there then return s.end();
    s.begin();
    for(auto it =s.begin() ; it!=s.end(); it++){
        cout<<*it<<" ";
    }

    s.clear() // clear everything
    s.size()  // return size
    s.count(5)  // return that how many times '5' is present 
    s.erase(10) // remove 10

    return 0;
}