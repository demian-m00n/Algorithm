#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int m , n , k;
int board[102][102];
int dx[4] {1,0,-1,0};
int dy[4] {0,-1,0,1};

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> m >> n >> k ;
  while(k--){
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1 ; i < x2 ; ++i){
      for(int j = y1 ; j < y2 ; ++j){
        board[j][i] = 1 ;
      }
    }

  }

  vector<int> ans;
  int cnt = 0;

  for(int i = 0 ; i < m ; ++i){
    for(int j = 0 ; j < n ; ++j){
      if(board[i][j] == 1) continue;
      int area = 0;
      ++cnt;
      queue<pair<int,int>> Q;
      Q.push({i,j});
      board[i][j] = 1;
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        ++area;
        for(int dir = 0 ; dir < 4 ; ++dir){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if( nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;
          if( board[nx][ny] == 1)
            continue;
          Q.push({nx,ny});
          board[nx][ny] = 1;
        }
      }
      ans.push_back(area);
    }
  }
  sort(ans.begin(),ans.end());
  cout << cnt << '\n';
  for(auto x : ans) cout << x << ' ';
}