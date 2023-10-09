#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int board[102][102];
bool vis[102][102];
int dx[4] {1,0,-1,0};
int dy[4] {0,-1,0,1};

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;

  int maxH = 0;

  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < n ; ++j){
      cin >> board[i][j];
      maxH = max(maxH,board[i][j]);
    }
  }

  int ans = 0;

  for(int i = 0 ; i <= maxH ; ++i){
    int cnt = 0;
    for(int j = 0 ; j < n ; ++j)
      fill(vis[j],vis[j]+n,false);
    for(int j = 0 ; j < n ; ++j){
      for(int k = 0 ; k < n ; ++k){
        if(vis[j][k] || board[j][k] <= i) continue;
        queue<pair<int,int>> Q;
        ++cnt;
        Q.push({j,k});
        vis[j][k] = true;
        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
          for(int dir = 0 ; dir < 4 ; ++dir){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
              continue;
            if(board[nx][ny] <= i || vis[nx][ny])
              continue;
            Q.push({nx,ny});
            vis[nx][ny] = true;
          }
        }
      }
    }
    ans = max(ans,cnt);
  }

  cout << ans;
}