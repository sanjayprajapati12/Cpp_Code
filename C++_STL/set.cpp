#include<bits/stdc++.h>
using namespace std;
void print(set<string> &s){
    for(auto value:s){
        cout<<value<<endl;
    }
}

// lower_bound for first element in pair 
template <class T>
auto lower_bound_first(const std::set<std::pair<T, T>>& s, T first)
{
   static constexpr T min = std::numeric_limits<T>::min();

   return s.lower_bound({first, min});
}

int main(){
    set<string> s;
    s.insert("sanjay"); // log(n)
    s.insert("sn");
    print(s);
    auto it3 = s.lower_bound("sanjay"); // this is how u use lower bound in set
    auto it = s.find("sanjay"); //log(n)
    if(it!=s.end()){
        cout<<*it<<endl;
    }
    s.erase("sn"); // remove sn [take it as well as string]

    unordered_set<string> s1;
    // O(1)
    //  oreder ma na hoy
    // pair ,vector , map e unordered_set compile na thay

    multiset<string> s2;
    // duplicates are allowed
    s.insert("sanjay"); // log(n)
    s.insert("sanjay"); 
    s.insert("sn");

    // s.insert(element).first = return iterator where element is pointing
    // s.insert(element).second = return true if element is inserted , return false if there exist elment ;

    // sirf first wala "sanjay" erase hoga
    auto it1 = s2.find("sanjay"); //log(n)
    if(it1!=s2.end()){
        s2.erase(it1);
    }

    s2.erase("sanjay"); //--> both "sanjay" are erased

    // lower_bound(s.begin(),s.end(),element)  -> this will give tle 
    // set/map s =  {4,4,5,7,7,8,9}
    // s.lower_bound(6) = 7 ka it
    // s.lower_bound(7) = 7 ka it
    // s.lower_bound(10) = s.end() [map ke case me key ka it]
    // s.upper_bound(6) = 7 ka it
    // s.upper_bound(7) = 8 ka it
    
    return 0;
}


    // set with costum operator
    // set<int,cmp> s;
    //  struct cmp{
    //     bool operator()(const int p, const int q) const {
    //            return (p>q);
    //     }
    //  };