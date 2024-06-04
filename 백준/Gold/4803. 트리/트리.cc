#include<bits/stdc++.h>
using namespace std;

vector<int> adj[510];
bool vis[510], isTree;
int N, M, u, v, trees, tc = 0;

void dfs(int cur, int prev){
  for(int nxt: adj[cur]){
    if(nxt == prev) continue;
    if(vis[nxt]){
      isTree = false;
      continue;
    }
    vis[nxt] = true;
    dfs(nxt, cur);
  }
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  while(1){
    cin >> N >> M;
    if(!N && !M) break;
    fill(vis, vis + N + 1, 0);
    for(int i = 1 ; i <= N ; ++i)
      adj[i].clear();
    trees = 0;
    for(int i = 0 ; i < M ; ++i){
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(int i = 1; i <= N ; ++i){
      if(vis[i]) continue;
      vis[i] = true;
      isTree = true;
      dfs(i, -1);
      trees += isTree;
    }
    cout << "Case " << ++tc << ": ";
    if (!trees)
      cout << "No trees." << '\n';
    else if (trees == 1)
      cout << "There is one tree." << '\n';
    else
      cout << "A forest of " << trees << " trees." << '\n';
    }

}