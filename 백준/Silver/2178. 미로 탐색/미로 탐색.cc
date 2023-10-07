#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n , m ;
string adj[102];
int dis[102][102];
int dx[4] {1,0,-1,0};
int dy[4] {0,-1,0,1};

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m ;

  for(int i = 0 ; i < n ; ++i){
    cin >> adj[i];
  }

  for(int i = 0 ; i < n ; ++i)
    fill(dis[i],dis[i] + m , -1);
  
  queue<pair<int,int>> Q;
  Q.push({0,0});
  dis[0][0] = 1 ;
  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
    for(int dir = 0 ; dir < 4 ; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      if(dis[nx][ny] >= 0 || adj[nx][ny] != '1')
        continue;
      dis[nx][ny] = dis[cur.X][cur.Y] + 1 ;
      Q.push({nx,ny});
    }
  }

  cout << dis[n-1][m-1];
}