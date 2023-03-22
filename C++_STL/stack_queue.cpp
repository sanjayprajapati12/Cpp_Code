#include<bits/stdc++.h>
#define ll long long
using namespace std;
    
int main(){
    
    stack<int> s;
    s.push(2); 
    s.push(3);
    s.push(4);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    queue<string> q;
    q.push("sanjay");
    q.push("jay");
    q.push("abc");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}