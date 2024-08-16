#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 0x7f7f7f7f;
int N, M, A, B;
ll C;
ll mn = 1, mx;

vector<pair<ll, int>> adj[100'002];
ll d[500'002];

bool solve(ll limit){
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
  memset(d, 0x3f, sizeof(d));

  d[A] = 0;
  pq.push({0, A});
  while(!pq.empty()){
    auto [cost, cur] = pq.top(); pq.pop();
    if(d[cur] != cost) continue;
    for(auto [dist, nxt] : adj[cur]){
      if(dist > limit) continue;
      dist += cost;
      if(d[nxt] <= dist) continue;
      d[nxt] = dist;
      pq.push({dist, nxt});
    }
  }

  if(d[B] > C) return 0;
  return 1;
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> A >> B >> C;

  fill(d + 1, d + N + 1, INF);

  int u, v;
  ll w;
  while (M--)
  {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
    mx = max(mx, w);
  }

  while(mn < mx){
    ll mid = (mn + mx) / 2;
    if(solve(mid)) mx = mid;
    else mn = mid + 1;
  }

  if(solve(mn)) cout << mn;
  else cout << -1;

  return 0;
}