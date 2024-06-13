#include<bits/stdc++.h>
using namespace std;

int t, N, K, X, Y, W;

int dur[1002];
int indeg[1002];
vector<int> adj[1002];
int dp[1002];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> t;

  while(t--){
    cin >> N >> K;

    for(int i = 1 ; i <= N ; ++i)
      cin >> dur[i];

    for(int i = 1 ; i <= K ; ++i){
      cin >> X >> Y;
      ++indeg[Y];
      adj[X].push_back(Y);
    }

    cin >> W;

    queue<int> Q;


    for(int i = 1 ; i <= N ; ++i){
      if(indeg[i] == 0){
        Q.push(i);
        dp[i] = dur[i];
      }
    }

    while(!Q.empty()){
      int cur = Q.front(); Q.pop();
      for(int i = 0 ; i < adj[cur].size() ; ++i){
        int nxt = adj[cur][i];
        --indeg[nxt];
        dp[nxt] = max(dp[nxt], dp[cur] + dur[nxt]);
        if(indeg[nxt] == 0) Q.push(nxt);
      }
    }

    cout << dp[W] << ' ';

    fill(dur,dur + N + 1 , 0);
    fill(indeg,indeg + N + 1 , 0);
    fill(dp,dp + N + 1 , 0);

    for(int i = 0 ; i <= N ; ++i)
      adj[i].clear();

  }
}