#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MX = 100'000 * 10 + 5;
int unused = 2;
int n;
int nxt[MX][26];
unordered_map<string, int> x;

int c2i(char c){
  return c - 'a';
}

void insert(string& s) {
  int cur = ROOT;
  for (auto c : s) {
    if (nxt[cur][c2i(c)] == -1)
      nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
}

string find(string& s) {
  int cur = ROOT;
  string alias = "";
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    alias += c;
    if (nxt[cur][c2i(c)] == -1) return alias;
    cur = nxt[cur][c2i(c)];
  }
  if (x[s] > 1) alias += to_string(x[s]);
  return alias;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0 ; i < MX ; ++i)
    fill(nxt[i], nxt[i] + 26, -1);

  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    x[s]++;
    cout << find(s) << '\n';
    insert(s);
  }

  return 0;
}