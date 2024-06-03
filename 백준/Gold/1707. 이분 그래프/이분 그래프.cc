#include<bits/stdc++.h>
using namespace std;

int K, V, E, A, B;
bool ans;
int mark[20005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> K;
  while(K--){
    cin >> V >> E;
    fill(mark, mark + V + 1, -1);
    vector<vector<int>> adj(V + 1);
    ans = true;

    for(int i = 0 ; i < E ; ++i){
      cin >> A >> B;
      adj[A].push_back(B);
      adj[B].push_back(A);
    }

    for(int i = 1 ; i <= V ; ++i){
      if(mark[i] != -1) continue;

      queue<int> q;
      q.push(i);
      mark[i] = 0;

      while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
          if(mark[nxt] != -1){
            if(mark[nxt] == mark[cur]){
              ans = false;
              break;
            }
            else continue;
          }
          mark[nxt] = (mark[cur] + 1) % 2;
          q.push(nxt);
        }
      }
      if(!ans) break;
    }

    if(ans) cout << "YES\n";
    else cout << "NO\n";
  }
}