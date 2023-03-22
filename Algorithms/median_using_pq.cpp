#include<bits/stdc++.h>
using namespace std;

struct med{
    priority_queue<int, vector<int>, greater<int> > up;
    priority_queue<int> low;

    void push_kar(int v){
        if(up.empty()){
            up.push(v);
            return;
        }
        if(v>=up.top()){
            up.push(v);
        }
        else{
            low.push(v);
        }

        if(up.size()-low.size()==2){
            low.push(up.top());
            up.pop();
        }
        else if(low.size()-up.size()==2){
            up.push(low.top());
            low.pop();
        }
    }

    double get(){
        if(low.size()==up.size()){
            return (low.top()+up.top())/2.0;
        }
        else if(up.size()>low.size()){
            return (up.top());
        }
        else{
            return (low.top());
        }
    }
};

int32_t main(){
    med m;
    m.push_kar(2);
    cout<<m.get()<<endl;
    m.push_kar(10);
    cout<<m.get()<<endl;
    m.push_kar(1);
    cout<<m.get()<<endl;
    m.push_kar(8);
    cout<<m.get()<<endl;
    m.push_kar(3);
    cout<<m.get()<<endl;
    m.push_kar(8);
    cout<<m.get()<<endl;
    return 0;
}