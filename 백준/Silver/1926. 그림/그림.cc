#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] {1,0,-1,0};
int dy[4] {0,-1,0,1};
int adj[502][502];

int main(void){
  int n , m ;
  cin >> n >> m ;
  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < m ; ++j)
      cin >> adj[i][j] ;
  }

  int area = 0 ;
  int cnt = 0 ;

  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < m ; ++j){
      if (adj[i][j] == 0) continue;
      ++ cnt ;
      int a = 0;
      queue<pair<int,int>> Q;
      Q.push({i,j}) ;
      adj[i][j] = 0 ;
      while(!Q.empty()){
        int x = Q.front().X ;
        int y = Q.front().Y ; Q.pop() ;
        ++ a ;

        for(int k = 0 ; k < 4 ; ++k){
          int nx = x + dx[k];
          int ny = y + dy[k];
          if( nx < 0 || ny < 0 || nx >= n || ny >= m || adj[nx][ny] == 0)
            continue;
          Q.push({nx,ny});
          adj[nx][ny] = 0 ;
        }

      }
      area = max(area,a);
    }
  }
  cout << cnt << '\n' << area ;
}