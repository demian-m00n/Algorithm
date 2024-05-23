#include<bits/stdc++.h>
using namespace std;

int N, t, u, v, ans = 0;
vector<int> adj[101];
bool vis[101];

int main(void){
  cin >> N >> t;
  
  while(t--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  stack<int> st;
  st.push(1);
  vis[1] = true;

  while(!st.empty()){
    auto cur = st.top(); st.pop();
    for(auto next : adj[cur]){
      if(vis[next]) continue;
      st.push(next);
      vis[next] = true;
    }
    ++ans;
  }

  cout << ans - 1;
}