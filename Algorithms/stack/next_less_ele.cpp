#include<bits/stdc++.h>
using namespace std;

// stack is always in increasing / decreasing
void _print(vector<int> &arr , stack<int> s){
    while(!s.empty()){
        cout<<arr[s.top()]<<" ";
        s.pop();
    }
    cout<<endl;
}

vector<int> nextGreater_myway(vector<int>& arr){
    int n = arr.size();
    vector<int> st;
    vector<int> ans(n);
    for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty() && arr[i]>=arr[st.back()]){
            st.pop_back();
        }
        ans[i] = st.empty() ? n : st.back();
        st.push_back(i);
    }
    return ans;
}

vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
	stack<int> s;	
    vector<int> result(n, n);
	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] <= arr[i]) {
			result[s.top()] = i;	
			s.pop();
		}
		s.push(i);

        // monotonic in nature 
        // _print(arr,s);
	}
    return result;
}

int32_t main(){
    // vector<int> A = {3,7,8,4};
    // vector<int> A = {1,2,3,2,1,4,4,5};
    vector<int> A = {2,7,4,3,5};
    vector<int> ans = nextGreater(A);
    vector<int> ans1 = nextGreater_myway(A);
    for(auto &x:ans){
        cout<<x<<' ';
    }
    cout<<endl;
    for(auto &x:ans1){
        cout<<x<<' ';
    }
    cout<<endl;
    
    // next_less[i] = j means A[j] is the next less element of A[i].
    // next_less[i] = -1 means there is no next less element of A[i].
    // vector<int> next_less(A.size(), -1);
    // stack<int> stk;
    
    // for(int i = 0; i < A.size(); i++){
    //     while(!stk.empty() && A[stk.top()] > A[i]){
    //         auto x = stk.top(); 
    //         stk.pop();
    //         next_less[x] = i;
    //     }
    //     stk.push(i);
    // }
    
    // for(int i=0 ;i<A.size() ;i++){
    //     if(next_less[i]==-1){
    //         cout<<-1<<" ";
    //     }
    //     else cout<<A[next_less[i]]<<' ';
    // }

    return 0;
}