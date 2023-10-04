#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e, st, en;
vector<pair<int,int>> adj[1005];
const int INF = 1e9+10;
int pre[1005];
int dis[1005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> v >> e ;
  fill(dis,dis+v+1,INF);
  while(e--){
    int a, b, c;
    cin >> a >> b >> c ;
    adj[a].push_back({c,b});
  }

  cin >> st >> en ;

  priority_queue<pair<int,int>,
                  vector<pair<int,int>>,
                  greater<pair<int,int>>> pQ;

  dis[st] = 0;
  pQ.push({dis[st],st});
  while(!pQ.empty()){
    auto cur = pQ.top(); pQ.pop();
    if(dis[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(dis[nxt.Y] <= dis[cur.Y] + nxt.X) continue;
      dis[nxt.Y] = dis[cur.Y] + nxt.X;
      pQ.push({dis[nxt.Y],nxt.Y});
      pre[nxt.Y] = cur.Y;
    }
  }

  cout << dis[en] << '\n';
  vector<int> p;
  int cur = en;
  while(cur!=st){
    p.push_back(cur);
    cur = pre[cur];
  }
  p.push_back(cur);
  reverse(p.begin(),p.end());
  cout << p.size() << '\n';
  for(auto x : p) cout << x << ' ';
}