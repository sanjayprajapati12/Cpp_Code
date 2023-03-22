#include<bits/stdc++.h>
#define ll long long
using namespace std;
// check if string is balanced or not 
//  ((()))() this is balanced
// (((())) this is not

int main(){
    string s;
    cin>>s;
    stack<string> stack;
    for(int i=0 ;i<s.length(); i++){
        if(s[i]=='('){
            stack.push("(");
        }
        else{
            stack.pop();
        }
    }
    if(stack.empty()){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"Not balanced"<<endl;
    }

    return 0;
}