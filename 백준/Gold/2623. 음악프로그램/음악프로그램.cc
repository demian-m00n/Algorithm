#include<bits/stdc++.h>
using namespace std;

const int MXN = 1'005;
int deg[MXN];
vector<int> adj[MXN];
vector<int> ans;
int N, M, singNum;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N >> M;

  for(int i = 0 ; i < M ; ++i){

    int cur, prev = -1;
    cin >> singNum;

    for(int j = 0 ; j < singNum ; ++j){
      cin >> cur;
      if(prev != -1){
        ++deg[cur];
        adj[prev].push_back(cur);
      }
      prev = cur;
    }
  }

  queue<int> q;

  for(int i = 1 ; i <= N ; ++i){
    if(deg[i] == 0) q.push(i);
  }

  while(!q.empty()){
    int cur = q.front(); q.pop();
    ans.push_back(cur);

    for(int nxt : adj[cur]){
      --deg[nxt];
      if(deg[nxt] == 0) q.push(nxt);
    }
  }

  if(ans.size() != N) cout << 0;
  else
    for(int num : ans)
      cout << num << '\n';

}