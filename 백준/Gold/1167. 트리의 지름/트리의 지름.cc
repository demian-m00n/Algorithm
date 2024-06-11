#include<bits/stdc++.h>
using namespace std;

const int MXN = 100'005;
int u, v, n, c, mxCost, mxNode;
vector<pair<int,int>> adj[MXN];
bool vis[MXN];

void dfs(int cur, int dist){
  if(mxCost < dist){
    mxCost = dist;
    mxNode = cur;
  }
  for(auto [nxtDist, nxt] : adj[cur]){
    if(vis[nxt]) continue;
    vis[nxt] = true;
    dfs(nxt,nxtDist + dist);
  }
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;

  for(int i = 1 ; i <= n ; ++i){
    cin >> u;
    while(1){
      cin >> v;
      if(v == -1) break;
      cin >> c;
      adj[u].push_back({c, v});
      adj[v].push_back({c, u});
    }
  }

  vis[1] = 1;
  dfs(1,0);
  fill(vis, vis + n + 1, 0);
  vis[mxNode] = 1;
  dfs(mxNode, 0);

  cout << mxCost;
}