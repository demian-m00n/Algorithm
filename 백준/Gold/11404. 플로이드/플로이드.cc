#include<bits/stdc++.h>
using namespace std;

int n , m ;
int adj[101][101];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m ;
  for(int i = 1 ; i <= n ; ++i)
    fill(adj[i],adj[i]+n+1,0x3f3f3f3f);
  for(int i = 0 ; i < m ; ++i){
    int a , b , cost ;
    cin >> a >> b >> cost ;
    adj[a][b] = min(adj[a][b],cost);
  }

  for(int i = 1 ; i <= n ; ++i) adj[i][i] = 0;

  for(int i = 1 ; i <= n ; ++i){
    for(int j = 1 ; j <= n ; ++j){
      for(int k = 1 ; k <= n ; ++k){
        adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);
      }
    }
  }

  for(int i = 1 ; i <= n ; ++i){
    for(int j = 1 ; j <= n ; ++j){
      if(adj[i][j] == 0x3f3f3f3f) cout << "0 " ;
      else cout << adj[i][j] << ' ' ;
    }
    cout << '\n' ;
  }
}