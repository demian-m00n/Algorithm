#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int m , n ;
int board[1002][1002];
int dis[1002][1002];
int dx[4] {1,0,-1,0};
int dy[4] {0,-1,0,1};

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> m >> n ;
  queue<pair<int,int>> Q;
  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < m ; ++j){
      cin >> board[i][j];
      if(board[i][j] == 1)
        Q.push({i,j});
      if(board[i][j] == 0)
        dis[i][j] = -1;
    }
  }

  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0 ; dir < 4 ; ++dir){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(dis[nx][ny] >= 0) continue;
      dis[nx][ny] = dis[cur.X][cur.Y] + 1;
      Q.push({nx,ny});
    }
  }
  int days = 0;
  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < m ; ++j){
      if(dis[i][j] == -1){
        cout << -1;
        return 0;
      }
      days = max(days, dis[i][j]);
    }
  }
  cout << days;
}