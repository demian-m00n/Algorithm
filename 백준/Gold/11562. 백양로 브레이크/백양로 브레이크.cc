#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, u, v, b, s, e;
int dis[252][252];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;

  for(int i = 1; i <= n ; ++i){
    fill(dis[i] + 1 , dis[i] + n + 1, INF);
    dis[i][i] = 0;
  }

  for(int i = 0 ; i < m ; ++i){
    cin >> u >> v >> b;
    dis[u][v] = 0;
    dis[v][u] = !b;
  }

  for(int k = 1 ; k <= n ; ++k){
    for(int i = 1 ; i <= n ; ++i){
      for(int j = 1;  j <= n ; ++j){
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }

  cin >> m;
  while(m--){
    cin >> s >> e;
    cout << dis[s][e] << '\n';
  }


}