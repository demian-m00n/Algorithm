#include<bits/stdc++.h>
using namespace std;

const int INF = 300'000'000;
int dis[402][402];
int V, E;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> V >> E;

  for(int i = 1 ; i <= V ; ++i){
    fill(dis[i] + 1, dis[i] + V + 1 , INF);
    dis[i][i] = 0;
  }

  int a, b, c;
  while(E--){
    cin >> a >> b >> c;
    dis[a][b] = c;
  }

  for(int k = 1 ; k <= V ; ++k)
    for(int i = 1 ; i <= V ; ++i)
      for(int j = 1 ; j <= V ; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);


  int mn = INF;
  for(int i = 1 ; i <= V ; ++i)
    for(int j = i + 1 ; j <= V ; ++j)
      mn = min(mn, dis[i][j] + dis[j][i]);

  if(mn == INF) mn = -1;
  
  cout << mn;
}