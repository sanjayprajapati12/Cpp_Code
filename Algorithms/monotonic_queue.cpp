#include<bits/stdc++.h>
using namespace std;

struct Max_Queue {
    // we can also implement this with dequeue
	vector<pair<int,int>> q;
	int l;

	void init() {
		q.clear();
		l = 0;
	}

	void push(ll val) {
		int freq = 1;
		while(q.size() > l && q.back().first <= val) {
			freq += q.back().second;
			q.pop_back();
		}
		q.emplace_back(val, freq);
	}

	void pop() {
		q[l].second--;
		if(q[l].second == 0) {
			l++;
		}
	}

	ll max() {
		if(l == q.size()) {
			return -1e18;
		}
		return q[l].first;
	}
};


int main() {
    Max_Queue q;
	q.init();
}