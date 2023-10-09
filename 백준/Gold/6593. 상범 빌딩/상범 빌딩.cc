#include<bits/stdc++.h>
using namespace std;

int l, r, c;
int dx[6] {1,0,-1,0,0,0};
int dy[6] {0,-1,0,1,0,0};
int dz[6] {0,0,0,0,-1,1};

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  while(true){
    cin >> l >> r >> c;
    if(l == 0 && r == 0 && c == 0) return 0;
    queue<tuple<int,int,int>> Q;
    char board[31][31][31];
    int dist[31][31][31];
    bool isEscape = false;

    for(int i = 0 ; i < l ; ++i)
      for(int j = 0 ; j < r ; ++j) fill(dist[i][j],dist[i][j]+c,0);

    for(int i = 0 ; i < l ; ++i){
      for(int j = 0 ; j < r ; ++j){
        for(int k = 0 ; k < c ; ++k){
          cin >> board[i][j][k];
          if(board[i][j][k] == 'S'){
            Q.push({i,j,k});
            dist[i][j][k] = 0;
          }
          else if(board[i][j][k] == '.') dist[i][j][k] = -1;
        }
      }
    }

    while(!Q.empty()){
      if(isEscape) break;
      auto cur = Q.front(); Q.pop();
      int curH, curX, curY;
      tie(curH, curX, curY) = cur;
      for(int dir = 0 ; dir < 6 ; ++dir){
        int nh = curH + dz[dir];
        int nx = curX + dx[dir];
        int ny = curY + dy[dir];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || nh < 0 || nh >= l)
          continue;
        if(board[nh][nx][ny] == '#' || dist[nh][nx][ny] > 0)
          continue;

        dist[nh][nx][ny] = dist[curH][curX][curY] + 1;
        if(board[nh][nx][ny] == 'E'){
          cout << "Escaped in " << dist[nh][nx][ny] << " minute(s).\n";
          isEscape = true;
          break;
        }
        Q.push({nh,nx,ny});
      }
    }
    while(!Q.empty()) Q.pop();
    if(!isEscape) cout << "Trapped!\n";
  }
}