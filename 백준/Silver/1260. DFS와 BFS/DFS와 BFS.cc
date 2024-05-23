#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];

void bfs(int st){
  fill(vis,vis+1005,false);
  queue<int> Q;
  Q.push(st);
  vis[st] = true;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      Q.push(nxt);
      vis[nxt] = true;
    }
  }
  cout << '\n';
}

void dfs(int st){
  fill(vis,vis+1005,false);
  stack<int> S;
  S.push(st);
  while(!S.empty()){
    auto cur = S.top(); S.pop();
    if(vis[cur]) continue;
    vis[cur] = true;
    cout << cur << ' ';
    for(int i = 0 ; i < adj[cur].size() ; ++i){
      auto nxt = adj[cur][adj[cur].size()-1-i];
      if(vis[nxt]) continue;
      S.push(nxt);
    }
  }
  cout << '\n';
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n , m , st ;
  cin >> n >> m >> st ;

  while(m--){
    int u , v ;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 1 ; i <= n ; ++i)
    sort(adj[i].begin(),adj[i].end());

  dfs(st);
  bfs(st);

}