#include <bits/stdc++.h>
using namespace std;
const int ROOT = 1;
int unused = 2;
const int MX = 500 * 10000 + 5;
int nxt[MX][26];
bool chk[MX];
int n, m;

int c2i(char c){
  return c -'a';
}

void insert(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = true;
}

bool find(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      return false;
    cur = nxt[cur][c2i(c)];
  }
  return true;
}


int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0 ; i < MX ; ++i)
    fill(nxt[i], nxt[i] + 26, -1);

  int ans = 0;

  cin >> n >> m;

  while(n--){
    string s;
    cin >> s;
    insert(s);
  }

  while(m--){
    string s;
    cin >> s;
    if(find(s))
      ans++;
  }

  cout << ans;

  return 0;
}