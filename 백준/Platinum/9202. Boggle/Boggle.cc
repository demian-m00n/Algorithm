#include <bits/stdc++.h>
using namespace std;

const int MX = 300000 * 8 + 5;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][26];
int chk[MX];

int mark = 2;

bool vis[4][4];
char board[4][4];

int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int ctoi(char c){
  return c - 'A';
}

void insert(string& s){
  int cur = ROOT;
  for(char c : s){
    if(nxt[cur][ctoi(c)] == -1)
      nxt[cur][ctoi(c)] = unused++;
    cur = nxt[cur][ctoi(c)];
  }
  chk[cur] = 1;
}

int point = 0, wordnum = 0;
string mxlen = "";

void find(int curx, int cury, int cur, string s){
  if(cur == -1) return;
  
  if(chk[cur] != 0 && chk[cur] != mark){
    chk[cur] = mark;
    point += score[s.size()];
    wordnum++;
    if(s.size() > mxlen.size()) mxlen = s;
    else if(s.size() == mxlen.size() && s < mxlen) mxlen = s;
  }

  for(int dir = 0; dir < 8; dir++){
    int nx = curx + dx[dir];
    int ny = cury + dy[dir];

    if(nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue;
    if(vis[nx][ny]) continue;

    char c = board[nx][ny];
    vis[nx][ny] = 1;
    find(nx, ny, nxt[cur][ctoi(c)], s + c);
    vis[nx][ny] = 0;
  }
}

void solve(){
  point = 0;
  wordnum = 0;
  mxlen = "";

  for(int x = 0; x < 4; x++)
    for(int y = 0; y < 4; y++) {
      vis[x][y] = 1;
      find(x, y, nxt[ROOT][ctoi(board[x][y])], string(1, board[x][y]));
      vis[x][y] = 0;
    }

  cout << point << ' ' << mxlen << ' ' << wordnum << '\n';
  mark++;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i] + 26, -1);

  int w;
  cin >> w;
  while(w--){
    cin >> s;
    insert(s);
  }

  int b;
  cin >> b;
  for(int i = 0; i < b; i++){
    for(int j = 0; j < 4; j++)
      cin >> board[j];
    
    solve();    
  }
}
