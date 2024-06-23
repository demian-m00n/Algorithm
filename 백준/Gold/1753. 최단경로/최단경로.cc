#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v , e ;
vector<pair<int,int>> adj[20005];
const int INF = 1e9+10;
int dis[20005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int k ;
  cin >> v >> e >> k ;
  fill(dis,dis+v+1,INF);
  while(e--){
    int a , b , c ;
    cin >> a >> b >> c ;
    adj[a].push_back({c,b});
  }
  priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>> pQ;

  dis[k] = 0 ;
  pQ.push({dis[k],k});
  while(!pQ.empty()){
    auto cur = pQ.top(); pQ.pop();
    if(dis[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(dis[nxt.Y] <= dis[cur.Y] + nxt.X) continue;
      dis[nxt.Y] = dis[cur.Y] + nxt.X ;
      pQ.push({dis[nxt.Y],nxt.Y});
    }
  }
  for(int i = 1 ; i <= v ; ++i){
    if(dis[i] == INF) cout << "INF\n" ;
    else cout << dis[i] << '\n' ;
  }
}