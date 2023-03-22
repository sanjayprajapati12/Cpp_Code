#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// https://en.cppreference.com/w/cpp/algorithm/lower_bound
// https://en.cppreference.com/w/cpp/algorithm/upper_bound

int main(){
    vector<int> s(10,3); //size 10 of element 3
    // v.size() --> O(1)
    vector<int> v2 = s ; //copy O(n)
    vector<int> &v3 = s ; //reference O(n) --> agar tum v me change karoge to v3 bhi change hoga

    vector<int> a= { 11,2 ,14, 3};
    sort(a.begin(), a.end());       //O(nlog(n))

    int array[8,9,7,6,4,5,1,2,3];
    sort(a,a+n); // intro sort == insertion + heap + quick 

    // 2, 3,11,14;

    bool present = binary_search(a.begin(),a.end() , 11) ;  //true
    present= binary_search(a.begin(),a.end() , 15) ;         //false

    a.push_back(100); //O(1)
    a.pop_back(); //O(1)

    a.push_back(100);
    a.push_back(100);
    a.push_back(100);
    a.push_back(100);
    a.push_back(123);

    // for sorted 
    vector<int>::iterator it1 = lower_bound(a.begin(), a.end(),100); //  if more than one 100 is present in vector than it returns FIRST 100's iterator , if there is no 100 , then it return iterator which hase value greater than 100
    vector<int>::iterator it2 = upper_bound(a.begin(), a.end(),100);  //  if more than one 100 is present in vector than it returns LAST 100's iterator , if there is no 100 , then it return iterator which hase value leser than 100 O(log(n)) set,map me O(n)
    cout<< *it1 <<" "<< *it2<<endl;
    cout<<it2 - it1<<endl ;

    // vector/array v =  {4,4,5,7,7,8,9}
    // lower_bound(6) = 7 ka it
    // lower_bound(7) = 7 ka it
    // lower_bound(10) = v.end() [array ke liye a+n return karega]
    // upper_bound(6) = 7 ka it
    // upper_bound(7) = 8 ka it

    // iterator on vector 
    vector<int> v = { 1,2,3,4,5,6};
    vector<int>::iterator it3;
    for(it3 = v.begin(); it3!=v.end(); it3++){
        cout<<*it3<<" ";
    }
    cout<<endl;
    
    // it++ --> next iterator
    // it+1 --> next location [invalid in map and set because their location's are not continuous]

    // iterator on vector of pair
    vector<pair<int,int>> v_p = { {1,2},{3,4},{5,6}};
    vector<pair<int,int>>::iterator it4;
    for(it4 = v_p.begin(); it4!=v_p.end(); it4++){
        cout<<(*it4).first<<" "<<(*it4).second<<endl;
    }
    // (*it4).first  <=> (it->first)
    for(it4 = v_p.begin(); it4!=v_p.end(); it4++){
        cout<<(it4->first)<<" "<<(it4->second)<<endl;
    }

    // value [here value's are copied] 
    for(int value : v){
        cout<<value<<" ";
    }
    cout<<endl;

    // value [here value's are not copied] --> reference
    for(int &value : v){
        value++;
        cout<<value<<" ";
    }
    cout<<endl;

    // auto on vector of pair
    for(auto value: v_p){
        cout<<(value.first)<<" "<<(value.second)<<endl;
    }

    return 0;
}