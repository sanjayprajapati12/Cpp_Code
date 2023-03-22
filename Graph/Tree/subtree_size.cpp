#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];

int sub_size[N];
void DFS(int v,int parent){
    sub_size[v]= 1;
    for(int child : graph[v]){
        if(child == parent)continue;
        DFS(child,v);
        sub_size[v] += sub_size[child];
    }
}

void reset(int n){
    for(int i=0 ;i<=n ;i++){
        sub_size[i]=0;
    }
}

int32_t main(){
    int n;cin>>n;
    int m = n-1; // edges
    while(m--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    reset(n);
    int root = 1; // if we change root sub_size array change 
    DFS(root,-1);

    for(int i=1 ; i<=n ;i++){
        cout<<i<<" ->  "<<sub_size[i]<<endl;
    }
    
    return 0;
}