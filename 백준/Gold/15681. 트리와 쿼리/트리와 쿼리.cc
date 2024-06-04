#include<bits/stdc++.h>
using namespace std;

int N, R, Q, u, v, q, subTreeSize[100005];
vector<int> adj[100005];
vector<bool> vis(100005);

int countSubtreeNode(int cur){
  vis[cur] = true;
  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;
    subTreeSize[cur] += countSubtreeNode(nxt);
  }
  subTreeSize[cur]++;
  return subTreeSize[cur];
}
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N >> R >> Q;

  for(int i = 1 ; i < N ; ++i){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  countSubtreeNode(R);
  while(Q--){
    cin >> q;
    cout << subTreeSize[q] << '\n';
  }
}