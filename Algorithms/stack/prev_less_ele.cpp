#include<bits/stdc++.h>
using namespace std;

void _print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
//  same as nextGreater , only diff is in this traveral is from end to begin
vector<int> prevGreater(vector<int>& arr) {
    int n = arr.size();
	stack<int> s;	
    vector<int> result(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;	
			s.pop();
		}
		s.push(i);
        _print(s);
	}
    return result;
}

int32_t main(){
    vector<int> A = {3,7,8,4};
    // previous_less[i] = j means A[j] is the previous less element of A[i].
    // previous_less[i] = -1 means there is no previous less element of A[i].
    vector<int> previous_less(A.size(), -1);
    stack<int> stk;
    for(int i = 0; i < A.size(); i++){
        while(!stk.empty() && A[stk.top()] > A[i]){
            stk.pop();
        }
        previous_less[i] = stk.empty()? -1: stk.top();
        stk.push(i);
    }
    // vector<int> temp = nextLess(A);
    // for(auto &x:temp){
    //     if(x==-1){
    //         cout<<x<<" ";
    //     }
    //     else{
    //         cout<<A[x]<<" ";
    //     }
    // }
    // cout<<endl;
    for(int i=0 ;i<A.size() ;i++){
        if(previous_less[i]==-1){
            cout<<-1<<" ";
        }
        else cout<<A[previous_less[i]]<<' ';
    }

    return 0;
}