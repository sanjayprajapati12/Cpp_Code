#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define N 10e5

int n , m ;
bool visited[1000][1000] ;

bool isValid(int x,int y){
    if(x<1 || x>n || y<1 || y>m) return false;
    if(visited[x][y]==true) return false;

    return true;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void DFS(int x,int y){
    visited[x][y] = true;
    cout<<x<<" "<<y<<endl;

    for(int i=0 ; i<4 ;i++){
        if(isValid(x + dx[i] , y+dy[i])) 
            DFS(x+dx[i],y+dy[i]);
    }
}



int32_t main(){
    // n--> rows , m-->columns
    cin>>n>>m;
    DFS(1,1);
    return 0;
}