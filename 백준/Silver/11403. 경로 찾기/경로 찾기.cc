#include<bits/stdc++.h>
using namespace std;

int N;
bool mtrx[102][102];
bool vis[102];

bool dfs(int st, int en){
  fill(vis,vis + N + 2, 0);
  stack<int> s;
  s.push(st);

  while(!s.empty()){
    int cur = s.top(); s.pop();

    if(vis[cur]) continue;
    if(cur != st) vis[cur] = 1;

    for(int nxt = 0 ; nxt < N ; ++nxt){
      if(vis[nxt]) continue;
      if(mtrx[cur][nxt]){
        if(nxt == en) return true;
        s.push(nxt);
      }
    }
  }
  return false;
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N;

  for(int i = 0 ; i < N ; ++i)
    for(int j = 0 ; j < N ; ++j)
      cin >> mtrx[i][j];

  for(int i = 0 ; i < N ; ++i){
    for(int j = 0 ; j < N ; ++j)
      cout << dfs(i, j) << ' ';
    cout << '\n';
  }

}