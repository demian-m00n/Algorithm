#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int N, M, a, b, t, K;
int dis[202][202];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> N >> M;

  for(int i = 1 ; i <= N ; ++i){
    fill(dis[i] + 1, dis[i] + N + 1, INF);
    dis[i][i] = 0;
  }

  for(int i = 0 ; i < M ; ++i){
    cin >> a >> b >> t;
    dis[a][b] = min(dis[a][b] , t);
  }

  for(int k = 1 ; k <= N ; ++k){
    for(int i = 1 ; i <= N ; ++i){
      for(int j = 1; j <= N ; ++j){
        int tmp = dis[i][k] + dis[k][j];
        if(dis[i][j] > tmp){
          dis[i][j] = tmp;
        }
      }
    }
  }

  vector<int> frineds;

  cin >> K;

  while(K--){
    int x;
    cin >> x;
    frineds.push_back(x);
  }

  vector<pair<int,int>> v;
  for(int i = 1; i <= N; i++) {
    int mx = 0;
    for(auto ci : frineds)
      mx = max(mx, dis[i][ci] + dis[ci][i]);
    v.push_back({mx, i});
  }
  sort(v.begin(), v.end());

  int mn = v[0].first;
  for(auto cur : v) {
    if(mn < cur.first) break;
    cout << cur.second << ' ';
  }

}