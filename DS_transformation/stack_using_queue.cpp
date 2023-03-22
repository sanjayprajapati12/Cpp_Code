#include <bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1,q2;
    int curr_size ;
    public:
    Stack(){
        curr_size = 0 ;
    }

    void push(int x){
        curr_size++;
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
 
    void pop(){
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;
    }
 
    int top(){
        if (q1.empty())
            return -1;
        return q1.front();
    }
 
    int size(){
        return curr_size;
    }

};

class Stack1 {
 
    queue<int> q;

public:
    void push(int data){
        int s = q.size();
        q.push(data);
    
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    void pop()
    {
        if (q.empty())
            cout << "No elements\n";
        else
            q.pop();
    }
    
    int top() { return (q.empty()) ? -1 : q.front(); }
    
    bool empty() { return (q.empty()); }
 
    void test(){
        queue<int> temp1 = q;
        cout<<"Testing ... "<<endl;
        cout<<"q"<<endl;
        while(!temp1.empty()){
            cout<<temp1.front()<<" ";
            temp1.pop();
        }
        cout<<endl;
        cout<<"Testing complete ! "<<endl;
        return ;
    }
};

int main(){

    cout<<"Using two queue"<<endl;
    Stack st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    while(st.top()!=-1){
        cout<<st.top()<<endl;
        st.pop();
    }

    cout<<"Using only one queue"<<endl;
    Stack1 st1;
    st1.push(5);
    st1.push(4);
    st1.push(3);
    st1.push(2);
    st1.push(1);
    while(st1.top()!=-1){
        cout<<st1.top()<<endl;
        st1.pop();
    }

    return 0;
}