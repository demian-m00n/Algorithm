#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[26];
bool vis[26][26];
int n;
int dx[4] {1,0,-1,0};
int dy[4] {0,-1,0,1};

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;
  for(int i = 0 ; i < n ; ++i) cin >> board[i];

  vector<int> ans;

  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < n ; ++j){
      if(board[i][j] == '0' || vis[i][j]) continue;
      int area = 1;
      queue<pair<int,int>> Q;
      Q.push({i,j});
      vis[i][j] = true;
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0 ; dir < 4 ; ++dir){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
          if(vis[nx][ny] || board[nx][ny] == '0')
            continue;
          Q.push({nx,ny});
          vis[nx][ny] = true;
          ++area;
        }
      }
      ans.push_back(area);
    }
  }
  cout << ans.size() << '\n';
  sort(ans.begin(),ans.end());
  for(auto x : ans) cout << x << '\n';
}