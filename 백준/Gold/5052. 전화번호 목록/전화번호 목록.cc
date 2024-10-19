#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused;
const int MX = 10 * 10000 + 5;
int t, n;
int nxt[MX][10];
int chk[MX];

int c2i(char c){
  return c - '0';
}

bool insert(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
    if(chk[cur])
      return 0;
  }
  if(cur != unused - 1) return 0;
  chk[cur] = 1;
  return 1;
}


int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--){
    for(int i = 0 ; i < MX ; ++i)
      fill(nxt[i], nxt[i] + 10, -1);

    fill(chk, chk + MX, 0);
    unused = ROOT + 1;
    bool ans = 1;

    cin >> n;
    string s;
    while(n--){
      cin >> s;
      if(!insert(s)) ans = 0;
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}