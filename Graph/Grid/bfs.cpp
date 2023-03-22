#include<bits/stdc++.h>
using namespace std;
// simply find connected commponent 
#define pb push_back
#define N 10e5

int n , m ;
bool visited[1001][1001] ;
int d[1001][1001];
int grid[1001][1001];


bool isValid(int x,int y){
    if(x<1 || x>n || y<1 || y>m) return false;

    if(visited[x][y]==true) return false;

    return true;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


void BFS(int x,int y){
    queue<pair<int,int>> q;
    d[x][y]=0;
    visited[x][y] = true;
    q.push({x,y});

    while(!q.empty()){
        // bool flag = true;
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        for(int i=0 ; i<4 ;i++){
            if(isValid(x + dx[i] , y+dy[i])){
                int newX = x + dx[i];
                int newY = y + dy[i];
                q.push({newX,newY});

                visited[newX][newY] = true;
                d[newX][newY] = d[x][y] + 1;
            } 
        }
        
    }
}



int32_t main(){
    // n--> rows , m-->columns
    cin>>n>>m;
    int x,y;
    cin>>x>>y;
    BFS(x,y);


    cout<<"Distance : "<<endl;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=m;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}