#include<bits/stdc++.h>
using namespace std;

int adj[21][21];
int n;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> n;

  for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j)
      cin >> adj[i][j];
  
  vector<int> team(n);
  fill(team.begin() + n / 2, team.end(), 1);

  int ans = 0x7f7f7f7f;

  do{
    int diff = 0;
    for(int i = 0 ; i < n ; ++i){
      for(int j = i + 1 ; j < n ; ++j){
        if(team[i] != team[j]) continue;
        if(team[i] == 0) diff += (adj[i][j] + adj[j][i]);
        else diff -= (adj[i][j] + adj[j][i]);
      }
    }
    ans = min(ans, abs(diff));
  } while(next_permutation(team.begin(), team.end()));
  cout << ans;
}