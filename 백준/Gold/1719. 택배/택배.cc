#include<bits/stdc++.h>
using namespace std;

int N, M, a, b, t;
const int INF = 0x3f3f3f3f;
int nxt[202][202];
int dis[202][202];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> N >> M;

  for(int i = 1 ; i <= N ; ++i){
    fill(dis[i] + 1, dis[i] + N + 1, INF);
    dis[i][i] = 0;
  }

  for(int i = 1 ; i <= M ; ++i){
    cin >> a >> b >> t;
    dis[a][b] = t;
    dis[b][a] = t;
    nxt[a][b] = b;
    nxt[b][a] = a;
  }

  for(int k = 1 ; k <= N ; ++k){
    for(int i = 1 ; i <= N ; ++i){
      for(int j = 1 ; j <= N ; ++j){
        int tmp = dis[i][k] + dis[k][j];
        if(dis[i][j] > tmp){
          dis[i][j] = tmp;
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }

  for(int i = 1 ; i <= N ; ++i){
    for(int j = 1 ; j <= N ; ++j){
      if(i == j){
        cout << "- ";
      }
      else
        cout << nxt[i][j] << ' ';
    }
    cout << '\n';
  }
}