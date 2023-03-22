// problem:
// https://www.spoj.com/problems/DQUERY/
// O( (N+Q) * sqrt N )

#include<bits/stdc++.h>
using namespace std;

#define int long long int 
#define INF 1e18;
#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

struct node {
	int L, R, id;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		return (x.L/BLOCK < y.L/BLOCK);
	}
	return (x.R < y.R);
}

void add(int position) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
		answer++;
	}
}

void remove(int position){
	cnt[a[position]]--;
	if(cnt[a[position]] == 0) {
		answer--;
	}
}

int32_t main(){
 	int n;
    cin>>n;
 	for(int i=0; i<n; i++){
 		cin>>a[i];
   }

	int m;
    cin>>m;
	for(int i=0; i<m; i++) {
		cin>>q[i].L>>q[i].R;
		q[i].L; q[i].R;
		q[i].id = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = -1;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
        // cout<<"currentL -> "<<currentL<<endl;
		while(currentL > L) {
			currentL--;
			add(currentL);
		}
        // cout<<"currentL -> "<<currentL<<endl;
		while(currentR < R) {
			currentR++;
			add(currentR);
		}
        // cout<<"currentR -> "<<currentR<<endl;
		while(currentR > R) {
			remove(currentR);
			currentR--;
		}
        // cout<<"currentR -> "<<currentR<<endl;
		ans[q[i].id] = answer;
	}

	for(int i=0; i<m; i++){
		cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}