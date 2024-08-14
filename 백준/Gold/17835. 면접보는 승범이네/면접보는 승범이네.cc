#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 100'002;
const ll INF = 0x7f7f7f7f7f7f;

int N, M, K;
ll d[MX];
vector<pair<ll, int>> adj[MX];
priority_queue<pair<ll, int>,
               vector<pair<ll, int>>,
               greater<pair<ll, int>>>pq;

int main(void)
{
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M >> K;
  fill(d + 1, d + N + 1, INF);

  int u, v;
  ll w;
  while(M--){
    cin >> u >> v >> w;
    adj[v].push_back({w, u});
  }

  int ct;
  while(K--){
    cin >> ct;
    d[ct] = 0;
    pq.push({d[ct], ct});
  }

  while(!pq.empty()){
    int u, v;
    ll w, dw;
    tie(w, u) = pq.top(); pq.pop();
    if(d[u] != w) continue;
    for(auto nxt : adj[u]){
      tie(dw, v) = nxt;
      dw += w;
      if(dw >= d[v]) continue;
      d[v] = dw;
      pq.push({dw, v});
    }
  }

  int cidx = max_element(d + 1, d + N + 1) - d;
  cout << cidx << '\n' << d[cidx];
}