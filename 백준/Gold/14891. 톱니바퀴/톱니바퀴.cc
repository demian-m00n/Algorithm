#include <bits/stdc++.h>
using namespace std;

string board[4];

void go(int x, int dir) {
  int dirs[4] = {};
  dirs[x] = dir;
  
  int idx = x;
  while (idx > 0 && board[idx][6] != board[idx-1][2]){
    dirs[idx-1] = -dirs[idx];
    idx--;
  }
  
  idx = x;
  while (idx < 3 && board[idx][2] != board[idx+1][6]){
    dirs[idx+1] = -dirs[idx];
    idx++;
  }

  for(int i = 0; i < 4; i++) {
    if(dirs[i] == -1)
      rotate(board[i].begin(), board[i].begin()+1, board[i].end());    
    else if(dirs[i] == 1)
      rotate(board[i].begin(), board[i].begin()+7, board[i].end());
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for (int i = 0; i < 4; i++) cin >> board[i];
  int k;
  cin >> k;
  while (k--) {
    int x, dir;
    cin >> x >> dir;
    go(x - 1, dir);
  }
  int ans = 0;
  for (int i = 0; i < 4; i++)
    if (board[i][0] == '1') ans += (1 << i);
  cout << ans;
}